#pragma once
class IDrawable
{
public:
	virtual void draw() = 0;
	virtual void bind(int, int) = 0;
	/*virtual void setScreenPosition(int, int) = 0;*/
};

