#include "Game.h"
#include "SDL.h"

int main(int argc, char* argv[])
{
	Game* game = nullptr;
	game = new Game();

	game->init("SDL_Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}