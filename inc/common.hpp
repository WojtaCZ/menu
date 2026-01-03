#ifndef MENU_COMMON_H
#define MENU_COMMON_H

#include <cstdint>
#include <cstddef>
#include <utility> // for std::pair

namespace menu {

    enum class Anchor {
        TopLeft,    TopCenter,    TopRight,
        CenterLeft, Center,       CenterRight,
        BottomLeft, BottomCenter, BottomRight
    };

    /**
     * @brief Helper to calculate the top-left origin based on an anchor point.
     * Moved here so it can be shared by text, icons, and shapes.
     */
    inline std::pair<int, int> get_origin(int x, int y, int width, int height, Anchor anchor) {
        int finalX = x;
        int finalY = y;

        // X Adjustment
        switch (anchor) {
            case Anchor::TopCenter: case Anchor::Center: case Anchor::BottomCenter:
                finalX -= width / 2; break;
            case Anchor::TopRight: case Anchor::CenterRight: case Anchor::BottomRight:
                finalX -= width; break;
            default: break; 
        }

        // Y Adjustment
        switch (anchor) {
            case Anchor::CenterLeft: case Anchor::Center: case Anchor::CenterRight:
                finalY -= height / 2; break;
            case Anchor::BottomLeft: case Anchor::BottomCenter: case Anchor::BottomRight:
                finalY -= height; break;
            default: break;
        }
        return {finalX, finalY};
    }

    template <typename PixelType>
    class IFrameBuffer {
        public:
            virtual ~IFrameBuffer() = default;

            /**
             * @brief Get a pointer to the raw memory for a specific memory row.
             */

            virtual PixelType getPixel(int x, int y) const = 0;
            virtual void setPixel(int x, int y, PixelType color) = 0;

            virtual int getWidth() const = 0;
            virtual int getHeight() const = 0;
    };

}

#endif