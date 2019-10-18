#pragma once

class ServerScene;

class AISystem
{
private:
	ServerScene& sc;
public:
	AISystem(ServerScene& sc) : sc(sc) {}
	void Update(int dt);
};

