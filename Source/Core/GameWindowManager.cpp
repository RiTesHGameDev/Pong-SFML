#include ".../../../../Header/Core/GameWindowManager.h"

namespace Core {
	void GameWindowManager::initialize()
	{
		//Allocate memonry
		game_window = new RenderWindow();
		//Set up thw window with configured properties
		createGameWindow();
	}
	void GameWindowManager::createGameWindow()
	{
		//Create the window with specific dimensions and title
		game_window->create(VideoMode(game_window_width, game_window_height), game_title);
	}
	bool GameWindowManager::isGameRunning()
	{
		//Return true if window is open,false if closed
		return game_window->isOpen();
	}
	void GameWindowManager::render()
	{
		//This will handle the drawing operations
	}

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_window;
	}
}