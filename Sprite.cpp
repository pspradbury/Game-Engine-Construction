#include "Sprite.h"

Sprite::Sprite()
{
}


Sprite::~Sprite()
{
	delete[] m_data;
}

bool Sprite::Load(const std::string & filename)
{
	if (!HAPI.LoadTexture(filename, &m_data, m_width, m_height))
		return false;
	
	return true;
}

void Sprite::RenderFast(BYTE *screen, int screenWidth, int screenHeight, int textureWidth, int textureHeight, int posX, int posY)
{
	BYTE *screenTmp = screen + (posX + posY * screenWidth) * 4;
	BYTE *textureTmp = m_data;

	for (int y = 0; y < m_height; y++)
	{
		memcpy(screenTmp, textureTmp, m_width * 4);

		textureTmp += m_width * 4;
		screenTmp += screenWidth * 4;
	}
}

void Sprite::Render(BYTE *screen, int screenWidth, int screenHeight, int posX, int posY)
{
	// Create rectangles for the screen and the rectangle to clip
	Rectangle screenRect(screenWidth, screenHeight);
	Rectangle clippedRect(m_width, m_height);

	// Translate rectangle to screen space
	clippedRect.Translate(posX, posY);

	// Clip the rectangle to the screen
	clippedRect.ClipTo(screenRect);

	// Translate the rectangle back into screen space
	clippedRect.Translate(-posX, -posY);

	// Clamp the screen position to 0
	if (posX < 0)
		posX = 0;

	if (posY < 0)
		posY = 0;

	BYTE *screenTmp = screen + (posX + posY * screenWidth) * 4;
	BYTE *textureTmp = m_data + (clippedRect.m_left + clippedRect.m_top * m_width) * 4;

	for (int y = 0; y < clippedRect.Height(); y++)
	{
		for (int x = 0; x < clippedRect.Width(); x++)
		{
			BYTE red = textureTmp[0];
			BYTE green = textureTmp[1];
			BYTE blue = textureTmp[2];
			BYTE alpha = textureTmp[3];

			if (alpha == 0)
			{

			}
			else if (alpha == 255)
			{
				memcpy(screenTmp, textureTmp, 4);
			}
			else
			{
				screenTmp[0] = screenTmp[0] + ((alpha*(red - screenTmp[0])) >> 8);
				screenTmp[1] = screenTmp[1] + ((alpha*(green - screenTmp[1])) >> 8);
				screenTmp[2] = screenTmp[2] + ((alpha*(blue - screenTmp[2])) >> 8);
			}

			textureTmp += 4;
			screenTmp += 4;
		}
		screenTmp += (screenWidth - clippedRect.Width()) * 4;
		textureTmp += (m_width - clippedRect.Width()) * 4;
	}
}
