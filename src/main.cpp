#define OLC_PGE_APPLICATION
#include "../includes/olcPixelGameEngine.h"

//#include "../includes/Letters.h"

#include "../includes/ViewSpriteSheet.h" 

ViewSpriteSheet cViewFontSprites;
//Breakout::CustomText cDrawLetters;
float fGameSpeed = 300.0f;

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Example";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here

		//cDrawLetters.SetAttributes(0 - cDrawLetters.GetWidth(), 0, 10, 5); // start off screen
		//cDrawLetters.AddLetters({B, R, E, A, K, O, U, T});

		cViewFontSprites.RenderSpriteSheet(this);
	
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame

		// handle events


		// update frame

		/*
		int x = cDrawLetters.GetStartX();
		int s = ScreenWidth();
		
		if ( cDrawLetters.GetStartX() < ScreenWidth() ) {
			cDrawLetters.MoveFromPosition(1, 0);
		} else {
			
			cDrawLetters.SetAttributes(0 - cDrawLetters.GetWidth(), cDrawLetters.GetStartY() + cDrawLetters.GetHeight(), 10, 5); // start off screen
		}
		*/
		
		// clear screen
		//Clear(olc::Pixel(0,0,0));

		// render
		//cDrawLetters.Render(this);

		return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(800, 600, 1, 1))
		demo.Start();

	return 0;
}