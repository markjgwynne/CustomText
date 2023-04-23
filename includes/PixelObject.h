#pragma once

#include "../includes/olcPixelGameEngine.h"

#include <string>
#include <vector>
#include <map>

struct PixelItem {
public:
    PixelItem() {};    

    //Standard pixel
    PixelItem(float x, float y, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        position = { x, y };
        pixel = { r, g, b, a };
    };
    PixelItem(olc::vf2d set_position, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        position = set_position;
        pixel = { r, g, b, a };
    };
    PixelItem(float x, float y, olc::Pixel set_pixel) {
        position = { x, y };
        pixel = set_pixel;
    };
    PixelItem(olc::vf2d set_position, olc::Pixel set_pixel) {
        position = set_position;
        pixel = set_pixel;
    };

    // Standard text
    PixelItem(float x, float y, uint8_t r, uint8_t g, uint8_t b, uint8_t a, std::string screenText, int screenTextSize) {
        position = { x, y };
        pixel = { r, g, b, a };
        sScreenText = screenText;
        iScreenTextSize = screenTextSize;
    };
    PixelItem(olc::vf2d set_position, uint8_t r, uint8_t g, uint8_t b, uint8_t a, std::string screenText, int screenTextSize) {
        position = set_position;
        pixel = { r, g, b, a };
        sScreenText = screenText;
        iScreenTextSize = screenTextSize;
    };
    PixelItem(float x, float y, olc::Pixel set_pixel, std::string screenText, int screenTextSize) {
        position = { x, y };
        pixel = set_pixel;
        sScreenText = screenText;
        iScreenTextSize = screenTextSize;
    };
    PixelItem(olc::vf2d set_position, olc::Pixel set_pixel, std::string screenText, int screenTextSize) {
        position = set_position;
        pixel = set_pixel;
        sScreenText = screenText;
        iScreenTextSize = screenTextSize;
    };

    olc::vf2d position;
    olc::Pixel pixel;
    std::string sScreenText;
    int iScreenTextSize;

};
