#pragma once
#include<HAPI_lib.h>
#include<unordered_map>

using namespace HAPISPACE;

class Sprite;

class Visualisation
{
private:
	// Screen Dimensions
	int m_screenWidth{ 1024 };
	int m_screenHeight{ 768 };

	BYTE *m_screen{ nullptr };

	std::unordered_map<std::string, Sprite*> m_SpriteMap;
public:
	Visualisation();
	~Visualisation();

	bool Initialise();
	bool CreateSprite(const std::string& filename, const std::string& name);

	void ClearToColour(HAPI_TColour colour);
	void ClearToGray(BYTE gray = 0);
	void RenderFast(const std::string& name,int posX, int posY);
	void Render(const std::string& name, int posX, int posY) const;
};

