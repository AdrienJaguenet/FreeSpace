#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL_ttf.h>

#include "game.hpp"

int main(int argc, char** argv)
{
	std::vector<std::string> args;

	for (int i(0); i < argc; ++i) {
		args.push_back(std::string(argv[i]));
	}

	TTF_Init();

	Game game(args);

	while (game.state == GAME_STATE_RUNNING) {
		SDL_Event e;
		while(SDL_PollEvent(&e))
			game.ProcessEvent(e);
		game.Update();
		game.Render();
	}

	TTF_Quit();

	return 0;
}
