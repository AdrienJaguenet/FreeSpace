#pragma once

class Camera;
class ClientScene;

class GraphicsSystem
{
private:
	bool debug;
public:
	void Render(Camera& c, ClientScene& sc);

	void ToggleDebug(bool v)
	{
		debug = v;
	}
};

