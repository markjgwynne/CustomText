#pragma once

#include "../includes/olcPixelGameEngine.h"

//fontRenderable.Sprite()->GetPixel(i + ox * 8 + vFontSpacing[c - 32].x, j + oy * 8).r > 0)


class ViewSpriteSheet {
private:



public:
    ViewSpriteSheet() {};
    
    void RenderSpriteSheet(olc::PixelGameEngine* pge) {

        int iOffsetX = 10, iOffsetY = 100, scale = 5;

        pge->DrawString(10, 10, "Spritesheet Width: " + std::to_string(pge->fontRenderable.Sprite()->width));
        pge->DrawString(10, 20, "Spritesheet Height: " + std::to_string(pge->fontRenderable.Sprite()->height));

        for ( int x = 0; x < pge->fontRenderable.Sprite()->width; x++ ) 
            for ( int y = 0; y < pge->fontRenderable.Sprite()->height; y++ )
                if ( pge->fontRenderable.Sprite()->GetPixel(x, y).r )
                    for (uint32_t is = 0; is < scale; is++)
			            for (uint32_t js = 0; js < scale; js++)
                            pge->Draw(iOffsetX + x + (x * scale) + is, iOffsetY + y + (y * scale) + js, olc::WHITE);
                       
    };

};