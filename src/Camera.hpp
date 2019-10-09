#pragma once

class Camera
{
private:
public:
	int x, y;
	float scale;
	Camera(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
		scale = 2.f;
	}
};

