#include <iostream>
#include "../../Header/Core/GameLoop.h"

namespace Core
{
	void GameLoop::Initialize()
	{
		game_window_manager = new GameWindowManager();
		event_manager = new EventManager();
		gameplay_manager = new GameplayManager(event_manager);
		SoundManager::Initialize();

		game_window_manager->Initialize();
	}
	bool GameLoop::IsGameRunning()
	{
		return game_window_manager->IsGameRunning();
	}
	void GameLoop::PollEvent()
	{
		event_manager->PollEvents(game_window_manager->GetGameWindow());
	}
	void GameLoop::Update()
	{
		gameplay_manager->Update();
	}
	void GameLoop::Render()
	{
		game_window_manager->ClearGameWindow();
		gameplay_manager->Render(game_window_manager->GetGameWindow());
		game_window_manager->DisplayGameWindow();
	}
}