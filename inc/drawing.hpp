#ifndef OLED_DRAWING_H
#define OLED_DRAWING_H

#pragma once
#include <bitset>
#include <array>
#include <cstddef>
#include <cstdint>

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
            constexpr bool pixel(std::size_t x, std::size_t y) const { return data_[y][Width - 1 - x]; }

        private:
            data_t data_;
    };
	

}

#endif 
