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
		game_window->create(VideoMode::getDesktopMode(), game_title,Style::Fullscreen);
	}
	bool GameWindowManager::isGameRunning()
	{
		//Return true if window is open,false if closed
		return game_window->isOpen();
	}
	void GameWindowManager::render()
	{
		game_window->clear(Color(0, 0, 30, 255));

		game_window->display();
	}

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_window;
	}
}