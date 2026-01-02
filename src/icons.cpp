
#include "drawing.hpp"
#include <bitset>

using namespace menu::drawing;

static constexpr icon<14, 8> battery_empty({
    std::bitset<14>("00111111111111"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("11100000000001"),
    std::bitset<14>("11100000000001"),
    std::bitset<14>("11100000000001"),
    std::bitset<14>("11100000000001"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("00111111111111"),
});

static constexpr icon<14, 8> battery_1_4({
    std::bitset<14>("00111111111111"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("11100000011101"),
    std::bitset<14>("11100000011101"),
    std::bitset<14>("11100000011101"),
    std::bitset<14>("11100000011101"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("00111111111111"),
});

static constexpr icon<14, 8> battery_2_4({
    std::bitset<14>("00111111111111"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("11100001111101"),
    std::bitset<14>("11100001111101"),
    std::bitset<14>("11100001111101"),
    std::bitset<14>("11100001111101"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("00111111111111"),
});

static constexpr icon<14, 8> battery_3_4({
    std::bitset<14>("00111111111111"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("11100011111101"),
    std::bitset<14>("11100011111101"),
    std::bitset<14>("11100011111101"),
    std::bitset<14>("11100011111101"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("00111111111111"),
});

static constexpr icon<14, 8> battery_full({
    std::bitset<14>("00111111111111"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("11101111111101"),
    std::bitset<14>("11101111111101"),
    std::bitset<14>("11101111111101"),
    std::bitset<14>("11101111111101"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("00111111111111"),
});

/* ============================
 * Wireless icons (14 × 10)
 * ============================ */



static constexpr icon<14, 10> wireless_1({
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000011000000"),
    std::bitset<14>("00000011000000"),
});

static constexpr icon<14, 10> wireless_2({
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000111100000"),
    std::bitset<14>("00001000010000"),
    std::bitset<14>("00000011000000"),
    std::bitset<14>("00000011000000"),
});

static constexpr icon<14, 10> wireless_3({
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000111100000"),
    std::bitset<14>("00011000011000"),
    std::bitset<14>("00100000000100"),
    std::bitset<14>("00100000000100"),
    std::bitset<14>("00000111100000"),
    std::bitset<14>("00001000010000"),
    std::bitset<14>("00000011000000"),
    std::bitset<14>("00000011000000"),
});


static constexpr icon<14, 10> wireless_4({
    std::bitset<14>("00001111110000"),
    std::bitset<14>("01000000000010"),
    std::bitset<14>("10000111100001"),
    std::bitset<14>("10011000011001"),
    std::bitset<14>("00100000000100"),
    std::bitset<14>("00100000000100"),
    std::bitset<14>("00000111100000"),
    std::bitset<14>("00001000010000"),
    std::bitset<14>("00000011000000"),
    std::bitset<14>("00000011000000"),
});


/* Kulicka (puntik vybrano) */
static constexpr icon<7, 7> dot_filled({
    std::bitset<7>("0011100"),
    std::bitset<7>("0111110"),
    std::bitset<7>("1111111"),
    std::bitset<7>("1111111"),
    std::bitset<7>("1111111"),
    std::bitset<7>("0111110"),
    std::bitset<7>("0011100"),
});

/* Kulicka obrys (puntik nevybrano) */
static constexpr icon<7, 7> dot_outline({
    std::bitset<7>("0011100"),
    std::bitset<7>("0100010"),
    std::bitset<7>("1000001"),
    std::bitset<7>("1000001"),
    std::bitset<7>("1000001"),
    std::bitset<7>("0100010"),
    std::bitset<7>("0011100"),
});

/* Sipka nahoru */
static constexpr icon<7, 7> arrow_up({
    std::bitset<7>("0001000"),
    std::bitset<7>("0011100"),
    std::bitset<7>("0011100"),
    std::bitset<7>("0111110"),
    std::bitset<7>("0111110"),
    std::bitset<7>("1111111"),
    std::bitset<7>("1111111"),
});

/* Sipka dolu */
static constexpr icon<7, 7> arrow_down({
    std::bitset<7>("1111111"),
    std::bitset<7>("1111111"),
    std::bitset<7>("0111110"),
    std::bitset<7>("0111110"),
    std::bitset<7>("0011100"),
    std::bitset<7>("0011100"),
    std::bitset<7>("0001000"),
});

/* Sipka vlevo prazdna */
static constexpr icon<8, 9> arrow_left_empty({
    std::bitset<8>("00000100"),
    std::bitset<8>("00011100"),
    std::bitset<8>("00111010"),
    std::bitset<8>("01110001"),
    std::bitset<8>("11000001"),
    std::bitset<8>("01110001"),
    std::bitset<8>("00111010"),
    std::bitset<8>("00011100"),
    std::bitset<8>("00000100"),
});

/* Sipka vlevo plna */
static constexpr icon<8, 9> arrow_left_filled({
    std::bitset<8>("00000100"),
    std::bitset<8>("00011100"),
    std::bitset<8>("00111110"),
    std::bitset<8>("01111111"),
    std::bitset<8>("11111111"),
    std::bitset<8>("01111111"),
    std::bitset<8>("00111110"),
    std::bitset<8>("00011100"),
    std::bitset<8>("00000100"),
});

/* Checkbox nevybrany */
static constexpr icon<9, 9> checkbox_empty({
    std::bitset<9>("111111111"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("111111111"),
});

/* Checkbox nevybrany – checked */
static constexpr icon<9, 9> checkbox_empty_checked({
    std::bitset<9>("111111111"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100111001"),
    std::bitset<9>("100111001"),
    std::bitset<9>("100111001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("111111111"),
});

/* Checkbox vybrany */
static constexpr icon<9, 9> checkbox_filled({
    std::bitset<9>("111111111"),
    std::bitset<9>("111111111"),
    std::bitset<9>("110000011"),
    std::bitset<9>("110000011"),
    std::bitset<9>("110000011"),
    std::bitset<9>("110000011"),
    std::bitset<9>("110000011"),
    std::bitset<9>("111111111"),
    std::bitset<9>("111111111"),
});

/* Checkbox vybrany – checked */
static constexpr icon<9, 9> checkbox_filled_checked({
    std::bitset<9>("111111111"),
    std::bitset<9>("111111111"),
    std::bitset<9>("110000011"),
    std::bitset<9>("110111011"),
    std::bitset<9>("110111011"),
    std::bitset<9>("110111011"),
    std::bitset<9>("110000011"),
    std::bitset<9>("111111111"),
    std::bitset<9>("111111111"),
});