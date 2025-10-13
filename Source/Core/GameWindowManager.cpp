#include ".../../../../Header/Core/GameWindowManager.h"

namespace Core {
	void GameWindowManager::Initialize()
	{
		//Allocate memonry
		game_window = new RenderWindow();
		//Set up thw window with configured properties
		CreateGameWindow();
	}
	void GameWindowManager::CreateGameWindow()
	{
		//Create the window with specific dimensions and title
		game_window->create(VideoMode::getDesktopMode(), game_title,Style::Default);
	}
	bool GameWindowManager::IsGameRunning()
	{
		//Return true if window is open,false if closed
		return game_window->isOpen();
	}

	RenderWindow* GameWindowManager::GetGameWindow()
	{
		return game_window;
	}
	void GameWindowManager::ClearGameWindow()
	{
		game_window->clear(Color(0,0,30,255));
	}
	void GameWindowManager::DisplayGameWindow()
	{
		game_window->display();
	}
}