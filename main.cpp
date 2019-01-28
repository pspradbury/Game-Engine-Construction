// MILESTONE 3

#if defined(DEBUG) | defined(_DEBUG)
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK,__FILE__, __LINE__)
#endif

#include<HAPI_lib.h>
#include "Visualisation.h"

using namespace HAPISPACE;

void HAPI_Main()
{
	// Initialise
	Visualisation viz;
	if (!viz.Initialise())
		return;

	// Create Player
	if (!viz.CreateSprite("Data\\playerSprite.tga", "player"))
		return;

	// Create Backgound
	if (!viz.CreateSprite("Data\\background.tga", "background"))
		return;

	// FPS
	HAPI.SetShowFPS(true, 0, 0);


	int posX{ 600 };
	int posY{ 500 };
	int moveSpeed{ 2 };

	const HAPI_TKeyboardData &keyData = HAPI.GetKeyboardData();

	while (HAPI.Update())
	{
		// Clear to black
		viz.ClearToGray();

		// Clear to colour
		viz.ClearToColour(HAPI_TColour::BLACK);

		// Draw Background
		viz.RenderFast("background", 0, 0);

		// Draw texture over the top
		viz.Render("player", posX, posY);

		// Player Movement
		if (keyData.scanCode['S'] || keyData.scanCode[HK_DOWN]) // down
		{
				posY += moveSpeed;
		}

		if (keyData.scanCode['W'] || keyData.scanCode[HK_UP]) // up
		{
				posY -= moveSpeed;
		}

		if (keyData.scanCode['D'] || keyData.scanCode[HK_RIGHT]) // right
		{
				posX += moveSpeed;
		}

		if (keyData.scanCode['A'] || keyData.scanCode[HK_LEFT]) // left
		{
				posX -= moveSpeed;
		}

		// Diagonal Movement
		if (keyData.scanCode['Z']) // down left
		{
			posY += moveSpeed;
			posX -= moveSpeed;
		}
		if (keyData.scanCode['Q']) // up left
		{
			posY -= moveSpeed;
			posX -= moveSpeed;
		}
		if (keyData.scanCode['E']) // right up
		{
			posX += moveSpeed;
			posY -= moveSpeed;
		}
		if (keyData.scanCode['X']) // right down
		{
			posX += moveSpeed;
			posY += moveSpeed;
		}
	}
}