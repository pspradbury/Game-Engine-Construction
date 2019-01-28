#include "Rectangle.h"
#include <algorithm>

Rectangle::Rectangle()
{

}

Rectangle::~Rectangle()
{

}

bool Rectangle::CompletelyInside(const Rectangle &other) const
{
	return false;
}

bool Rectangle::CompletelyOutside(const Rectangle &other) const
{
	return false;
}

void Rectangle::ClipTo(const Rectangle &other)
{
	m_left = std::max(m_left, other.m_left); //returns greater value
	m_right = std::min(m_right, other.m_right); //returns smaller value
	m_top = std::max(m_top, other.m_top);
	m_bottom = std::min(m_bottom, other.m_bottom);
}

void Rectangle::Translate(int screenX, int screenY)
{
	m_left += screenX;
	m_right += screenX;
	m_top += screenY;
	m_bottom += screenY;
}
