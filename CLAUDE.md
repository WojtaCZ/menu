# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is the `lib/menu` git submodule — a standalone GUI/menu library for embedded OLED displays. It is compiled as part of the parent `midicontrol-fw` CMake project (targeting STM32G431, Cortex-M4). The library has no build system of its own and no automated tests.

The parent project compiles with C++23, `-fno-exceptions`, `-fno-threadsafe-statics`, and `-Os`.

## Architecture

The library has two distinct layers:

### Low-level rendering layer (`namespace menu`, `namespace menu::drawing`, `namespace menu::text`)

Generic, hardware-independent, fully templated. These headers define the rendering primitives:

- **`inc/common.hpp`** — `IFrameBuffer<PixelType>` interface (virtual `getPixel`/`setPixel`/`getWidth`/`getHeight`), `Anchor` enum (9 anchor points: TopLeft…BottomRight), `get_origin()` helper that converts anchor+position into a top-left origin.

- **`inc/drawing.hpp`** — `menu::drawing::icon<Width, Height>` template backed by `std::array<std::bitset<Width>, Height>`. Pixel convention: x=0 is left/MSB. `drawIcon()` template function renders to any `IFrameBuffer`. Icons are defined in `src/icons.cpp` using binary string literals passed to `std::bitset` constructors.

- **`inc/text.hpp`** — `menu::text::character<Width, Height>` (same bitset pixel convention), abstract `font` interface, `font_ascii<Width, Height, Count, StartChar>` concrete template covering a contiguous ASCII range. `drawText()` template renders a `const char*` string via any `font` + `IFrameBuffer`. The three font instances (declared `extern` here, defined in `src/font_*.cpp`) are:
  - `Font_7x10` — 7×10, 95 chars from space
  - `Font_11x18` — 11×18, 95 chars from space
  - `Font_16x26` — 16×26, 95 chars from space

### High-level menu layer (`namespace GUI`, `namespace Oled`)

Coupled to the SH1106 OLED driver in the parent project. Uses `std::string`, `std::vector`, `std::map`, and `stmcpp::units`.

- **`inc/oled.hpp`** — `Oled::` namespace: display constants (130×64, I2C 0x3C, 2px X offset), `Color` enum, `Icon` enum (maps icon indices to font positions), and the OLED driver API (`init`, `update`, `fill`, `drawPixel`, `writeString`, `sleep`/`wakeup`, etc.).

- **`inc/menu.hpp`** — `GUI::` namespace: `Menu` (title map, `vector<Item*>`, selection state), `Item` (multilingual title via `map<Language, string>`, submenu/callback/none variants, icon pair), `Checkbox : Item`, `Splash`, `Paragraph`. Free functions: `display()`, `render()`, `renderForce()`, `keypress(UserInput::Key)`, `back()`, `scroll_callback()`. Language enum: `EN`, `CS`.

- **`src/menu.cpp`** — Implements the menu rendering loop, scroll logic, and input dispatch. The render scheduler runs at 30 ms; scroll pause is `MENU_SCROLL_PAUSE` (1000 ms). Two items are visible per screen (`MENU_LINES 2`) using the 11×18 font.

## Icon definition pattern

Icons are defined with `std::bitset<N>` binary string literals (MSB = left pixel, x=0):

```cpp
const icon<14, 8> my_icon({
    std::bitset<14>("00111111111111"),
    // ...
});
```

Declare new icons `extern` in `drawing.hpp` and define them in `src/icons.cpp`.

## Adding a new font size

1. Create `src/font_WxH.cpp` — define a `font_ascii<W, H, 95>` named `Font_WxH`.
2. Declare `extern const font_ascii<W, H, 95> Font_WxH;` in `inc/text.hpp`.
