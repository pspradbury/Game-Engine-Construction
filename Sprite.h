#pragma once
#include<HAPI_lib.h>
#include "Rectangle.h"

using namespace HAPISPACE;

class Sprite
{
private:
	int m_width;
	int m_height;
	BYTE* m_data{ nullptr };
public:
	Sprite();
	~Sprite();	

	bool Load(const std::string& filename);

	void RenderFast(BYTE *screen, int screenWidth, int screenHeight, int textureWidth, int textureHeight, int posX, int posY);
	void Render(BYTE *screen, int screenWidth, int screenHeight, int posX, int posY);
};

