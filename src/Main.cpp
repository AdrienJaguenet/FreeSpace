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
	sf::Event e;
	sf::Clock clock;

	while (game.state == GAME_STATE_RUNNING) {
		if (clock.getElapsedTime().asMilliseconds() > 10.f) {
			while(game.getWindow().pollEvent(e)) {
				game.ProcessEvent(e);
			}
			game.Update(clock.getElapsedTime().asMilliseconds());
			game.Render();
			clock.restart();
		}
	}

	return 0;
}
