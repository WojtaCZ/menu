#ifndef OLED_FONTS_H
#define OLED_FONTS_H

#include <cstdint>

namespace menu::text {
	class font {
		private:
				uint8_t width_;    /*!< Font width in pixels */
				uint8_t height_;   /*!< Font height in pixels */
				const uint16_t * data_; /*!< Pointer to data font data array */

		public:
			font(uint8_t width, uint8_t height, const uint16_t * data) : width_(width), height_(height), data_(data) {};
	};


	extern font Font_7x10;
	//extern Font Icon_7x10;
	extern font Font_11x18;
	//extern Font Icon_11x18;
	extern font Font_16x26;

}
#endif 
