#include <cmath>

#pragma once

class ClientScene;

class InputSystem
{
	ClientScene& scene;
public:
	InputSystem(ClientScene& scene);
	void StartThrusting();
	void StopThrusting();
	void StartBoost();
	void StopBoost();
	void LookAt(float x, float y);
	void Fire();
};

