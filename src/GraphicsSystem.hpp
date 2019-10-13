#pragma once

class Camera;
class Scene;

class GraphicsSystem
{
private:
	bool debug;
public:
	void Render(Camera& c, Scene& sc);

	void ToggleDebug(bool v)
	{
		debug = v;
	}
};

