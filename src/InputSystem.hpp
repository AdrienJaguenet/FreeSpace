#pragma once

class Scene;

class InputSystem
{
	Scene& scene;
public:
	InputSystem(Scene& scene);
	void StartThrusting();
	void StopThrusting();
	void StartBoost();
	void StopBoost();
	void LookAt(float x, float y);
	void Fire();
};

