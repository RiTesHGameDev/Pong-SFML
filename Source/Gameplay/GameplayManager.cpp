#include "../../Header/Gameplay/GameplayManager.h"

namespace Gameplay
{
	GameplayManager::GameplayManager(EventManager* manager)
	{
		Initialize();
		event_manager = manager;
	}
	void GameplayManager::Initialize()
	{
		boundary = new Boundary();
		ball = new Ball();
		player1 = new Paddle(player1_position_x, player1_position_y);
		player2 = new Paddle(player2_position_x, player2_position_y);
	}
	void GameplayManager::Render(RenderWindow* game_window)
	{
		boundary->Render(game_window);
		ball->Render(game_window);
		player1->Render(game_window);
		player2->Render(game_window);
	}
	void GameplayManager::Update()
	{
		ball->Update();

		player1->Update(event_manager->IsKeyPressed(Keyboard::W),
			event_manager->IsKeyPressed(Keyboard::S));

		player2->Update(event_manager->IsKeyPressed(Keyboard::Up),
			event_manager->IsKeyPressed(Keyboard::Down));
	}
}