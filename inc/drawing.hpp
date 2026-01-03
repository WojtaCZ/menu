#ifndef OLED_DRAWING_H
#define OLED_DRAWING_H

#pragma once
#include <bitset>
#include <array>
#include <cstddef>
#include <cstdint>
#include "common.hpp" // Required for IFrameBuffer and Anchor

namespace menu::drawing {

    template <std::size_t Width, std::size_t Height>
    class icon {
        public:
            using row_t  = std::bitset<Width>;
            using data_t = std::array<row_t, Height>;

            constexpr icon(const data_t& rows) : data_(rows) {}

            static constexpr std::size_t width  = Width;
            static constexpr std::size_t height = Height;

            constexpr const row_t& row(std::size_t y) const { return data_[y]; }
            
            // Standardizes pixel access (x=0 is Left/MSB)
            constexpr bool pixel(std::size_t x, std::size_t y) const { 
                return data_[y][Width - 1 - x]; 
            }

        private:
            data_t data_;
    };

    /**
     * @brief Draws an icon to the framebuffer.
     * Templated on IconType to allow compiler optimization of Width/Height constants.
     */
    template <typename PixelType, typename IconType>
    void drawIcon(menu::IFrameBuffer<PixelType>& fb, const IconType& icon, 
                  int x, int y, menu::Anchor anchor, PixelType color) {
        
        // 1. Calculate top-left start position using the common helper
        // We cast size_t to int for calculations
        auto origin = menu::get_origin(x, y, (int)IconType::width, (int)IconType::height, anchor);
        int startX = origin.first;
        int startY = origin.second;

        // 2. Render Loop
        for (std::size_t iy = 0; iy < IconType::height; ++iy) {
            int drawY = startY + int(iy);

            // Vertical Optimization: Skip row if off-screen
            if (drawY < 0 || drawY >= fb.getHeight()) continue;

            for (std::size_t ix = 0; ix < IconType::width; ++ix) {
                // Check if the icon bit is set
                if (icon.pixel(ix, iy)) {
                    int drawX = startX + int(ix);

                    // Horizontal Safety Check
                    if (drawX >= 0 && drawX < fb.getWidth()) {
                        fb.setPixel(drawX, drawY, color);
                    }
                }
            }
        }
    }

}

extern const menu::drawing::icon<14, 8> battery_empty;
extern const menu::drawing::icon<14, 8> battery_1_4;
extern const menu::drawing::icon<14, 8> battery_2_4;
extern const menu::drawing::icon<14, 8> battery_3_4;
extern const menu::drawing::icon<14, 8> battery_full;

#endif