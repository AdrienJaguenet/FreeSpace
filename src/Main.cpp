#include <iostream>
#include <vector>
#include <string>

#include <SFML/Window.hpp>

#include "Game.hpp"

int main(int argc, char** argv)
{
	std::vector<std::string> args;

	for (int i(0); i < argc; ++i) {
		args.push_back(std::string(argv[i]));
	}

	std::cerr << "Launching game..." << std::endl;
	Game game(args);

	while (game.state == GAME_STATE_RUNNING) {
		sf::Event e;
		while(game.getWindow().pollEvent(e))
			game.ProcessEvent(e);
		game.Update();
		game.Render();
	}

	return 0;
}
