#pragma once
class Rectangle
{	
public:
	Rectangle();
	~Rectangle();

	int m_left{ 0 }, m_right{ 0 }, m_top{ 0 }, m_bottom{ 0 };

	Rectangle(int l, int r, int t, int b) : m_left(l), m_right(r), m_top(t), m_bottom(b) {};
	Rectangle(int w, int h) : m_left(0), m_right(w), m_top(0), m_bottom(h) {};

	int Width() const { return m_right - m_left; }
	int Height() const { return m_bottom - m_top; }

	bool CompletelyInside(const Rectangle &other) const; // Test if othr rectangle is in this one.
	bool CompletelyOutside(const Rectangle &other) const; // Test if this rectangle is outside the other one.
	void ClipTo(const Rectangle &other); // Clips rectangle to other.
	void Translate(int screenX, int screenY); // Move the rectangle.
};

