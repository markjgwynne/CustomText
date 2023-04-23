#include "../includes/LetterObjects.h"
#include <vector>


Breakout::Letter::Letter(std::vector<Breakout::LetterPoints> vletter) { 
    m_vLetterPoints = vletter;
    SetAttributes();
};

void Breakout::Letter::SetAttributes() {
    for ( auto& letter_item : m_vLetterPoints ) {
        if( letter_item.X < m_iDrawX ) m_iDrawX = letter_item.X;
        if( letter_item.Y < m_iDrawY ) m_iDrawY = letter_item.Y;
        if( letter_item.X + (letter_item.Width * m_iResizeMultiplier) > m_iMaxX ) m_iMaxX = letter_item.X + (letter_item.Width * m_iResizeMultiplier);
        if( letter_item.Y * m_iResizeMultiplier > m_iMaxY ) m_iMaxY = letter_item.Y * m_iResizeMultiplier;
    }
    m_iWidth = m_iMaxX - m_iDrawX;
    m_iHeight = m_iMaxY - m_iDrawY;
};

void Breakout::Letter::MoveFromPosition(int new_x, int new_y) {
    m_iPositionX += new_x;
    m_iPositionY += new_y;
};

void Breakout::Letter::MoveToPosition(int position_x, int position_y) {
    m_iPositionX = position_x;
    m_iPositionY = position_y;
};

void Breakout::Letter::ResetPosition() {
    m_iPositionX = 0;
    m_iPositionY = 0;
};

void Breakout::Letter::Resize(int multiplier) {
    m_iResizeMultiplier = multiplier;
};

void Breakout::Letter::Render(olc::PixelGameEngine* pge) {
    for ( auto& letter_point : m_vLetterPoints ) {

        for (int m = 0; m < m_iResizeMultiplier; m++ ) {

            for (int x = 0; x < (letter_point.Width * m_iResizeMultiplier); x++ ) {            

                int x_resized = (letter_point.X * m_iResizeMultiplier) + x; 
                int y_resized = (letter_point.Y * m_iResizeMultiplier) + m;

                pge->Draw(m_iPositionX + x_resized, m_iPositionY + y_resized, olc::GREEN);

            }
        }
    }
};


Breakout::CustomText::CustomText(int starting_x, int starting_y, int spacing, int size_multiplier) {
    SetAttributes(starting_x, starting_y, spacing, size_multiplier);
};

void Breakout::CustomText::SetAttributes(int starting_x, int starting_y, int spacing, int size_multiplier) {
    m_iPositionX = starting_x;
    m_iPositionY = starting_y;
    m_iMultiplier = size_multiplier;
    m_iSpacing = spacing;

    if ( m_vLetters.size() > 0 ) {
        mUpdateLetterAttributes();
    }
};

void Breakout::CustomText::AddLetter(Breakout::Letter addLetter) {

    m_vLetters.push_back(addLetter);

    mUpdateLetterAttributes();
};

void Breakout::CustomText::AddLetters(std::vector<Letter> add_Letters) {

    for ( int i = 0; i < add_Letters.size(); i++ ) {
        
        m_vLetters.push_back(add_Letters[i]);
    }
    
    mUpdateLetterAttributes();

};

/*
    Move the position of the text from its current location by x and y.
*/
void Breakout::CustomText::MoveFromPosition(int move_x, int move_y) {
    m_iPositionX += move_x;
    m_iPositionY += move_y;

    for ( auto& letter_item : m_vLetters ) {
        letter_item.MoveFromPosition(move_x, move_y);
    }    

};

/*
    Move the position of the text to this x and y location.
*/
void Breakout::CustomText::MoveToPosition(int position_x, int position_y) {
    m_iPositionX = position_x;
    m_iPositionY = position_y;

    for ( auto& letter_item : m_vLetters ) {
        letter_item.MoveToPosition(position_x, position_y);
    }    

};

/*
    Render the text using a pointer to the PixelGameEngine.
*/
void Breakout::CustomText::Render(olc::PixelGameEngine* pge) {

    for ( auto& letter_item : m_vLetters ) {
        letter_item.Render(pge);
    }

};

void Breakout::CustomText::mUpdateLetterAttributes() {

    m_iWidth = 0;
    m_iHeight = 0;

    for ( int i = 0; i < m_vLetters.size(); i++ ) {

        m_vLetters[i].ResetPosition();
        m_vLetters[i].Resize(m_iMultiplier);

        if ( i == 0 ) {
            m_vLetters[i].MoveFromPosition(m_iPositionX, m_iPositionY);
        } else {
            m_vLetters[i].MoveFromPosition(m_vLetters[i-1].X() + m_vLetters[i-1].Width() + (m_iSpacing * m_iMultiplier), m_iPositionY);
        }

        m_iWidth += m_vLetters[i].Width();
        m_iHeight += m_vLetters[i].Height();
    }

    int t = 1;

};
