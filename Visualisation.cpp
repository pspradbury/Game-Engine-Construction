#include "Visualisation.h"
#include "Sprite.h"

Visualisation::Visualisation()
{
}


Visualisation::~Visualisation()
{
}

bool Visualisation::Initialise()
{
	if (!HAPI.Initialise(m_screenWidth, m_screenHeight, "Milestone 3"))
		return false;

	return true;
}

bool Visualisation::CreateSprite(const std::string & filename, const std::string & name)
{
	m_screen = HAPI.GetScreenPointer();

	Sprite *newSprite = new Sprite;
	if (!newSprite->Load(filename))
	{
		HAPI.UserMessage("File Not Found!", "Error");
		return false;

		delete newSprite;
		return false;
	}
	m_SpriteMap[name] = newSprite;

	return true;
}

void Visualisation::ClearToColour(HAPI_TColour colour)
{
	for (int i = 0; i < m_screenWidth * m_screenHeight * 4; i += 4)
	{
		m_screen[i + 0] = colour.red; // RED
		m_screen[i + 1] = colour.green; // GREEN
		m_screen[i + 2] = colour.blue; // BLUE
	}
}

void Visualisation::ClearToGray(BYTE gray)
{
	memset(m_screen, gray, m_screenWidth * m_screenHeight * 4);
}

void Visualisation::RenderFast(const std::string& name, int posX, int posY)
{
	if (m_SpriteMap.find(name) == m_SpriteMap.end())
		return;

	m_SpriteMap.at(name)->Render(m_screen, m_screenWidth, m_screenHeight, posX, posY);
}

void Visualisation::Render(const std::string& name, int posX, int posY) const
{
	if (m_SpriteMap.find(name) == m_SpriteMap.end())
		return;

	m_SpriteMap.at(name)->Render(m_screen, m_screenWidth, m_screenHeight, posX, posY);
}
