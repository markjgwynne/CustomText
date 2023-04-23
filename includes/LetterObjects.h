#pragma once

#include "../includes/PixelObject.h"
#include <vector>

namespace Breakout {

    struct LetterPoints {
        int X;
        int Y;
        int Width;
        LetterPoints(int x, int y, int width) {
            X = x;
            Y = y;
            Width = width;
        }
    };

    class Letter {
    private:
        std::vector<LetterPoints> m_vLetterPoints;
        int m_iWidth = 0;
        int m_iHeight = 0;
        int m_iDrawX = 0;
        int m_iDrawY = 0;
        int m_iMaxX = 0;
        int m_iMaxY = 0;
        int m_iPositionX = 0;
        int m_iPositionY = 0;
        int m_iResizeMultiplier = 1;

    public:
        Letter(std::vector<LetterPoints> vletter);

        int Width() { return m_iWidth; };
        int Height() { return m_iHeight; };
        int X() { return m_iPositionX + m_iDrawX; };
        int Y() { return m_iPositionY + m_iDrawY; };

        void SetAttributes();

        void MoveFromPosition(int move_x, int move_y);
        void MoveToPosition(int position_x, int position_y);

        void ResetPosition();

        void Resize(int multiplier);

        void Render(olc::PixelGameEngine* pge);

    };

    class CustomText {
        private:

        int m_iPositionX = 0;
        int m_iPositionY = 0;
        int m_iMultiplier;
        int m_iSpacing;
        int m_iWidth = 0;
        int m_iHeight = 0;

        std::vector<Letter> m_vLetters;

        void mUpdateLetterAttributes();
            
    public:
        CustomText() {};
        CustomText(int starting_x, int starting_y, int m_iSpacing = 3, int size_multiplier = 1);

        void SetAttributes(int starting_x, int starting_y, int m_iSpacing = 3, int size_multiplier = 1);

        void AddLetter(Letter add_Letter);

        void AddLetters(std::vector<Letter> add_Letters);

        void MoveFromPosition(int move_x, int move_y);
        void MoveToPosition(int position_x, int position_y);

        void Render(olc::PixelGameEngine* pge);

        int GetStartX() { return m_iPositionX; };
        int GetStartY() { return m_iPositionY; };
        int GetWidth() { return m_iWidth; };
        int GetHeight() { return m_iHeight; };

    };

}