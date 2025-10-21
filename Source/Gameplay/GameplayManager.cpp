#include "../../Header/Gameplay/GameplayManager.h"

namespace Gameplay
{
	GameplayManager::GameplayManager(EventManager* manager)
	{
		time_service = new TimeService();
		time_service->Initialize();
		Initialize();
		event_manager = manager;
	}
	void GameplayManager::Initialize()
	{
		boundary = new Boundary();
		ball = new Ball();
		player1 = new Paddle(player1_position_x, player1_position_y);
		player2 = new Paddle(player2_position_x, player2_position_y);
		ui_service = new UIService();
	}
	void GameplayManager::Render(RenderWindow* game_window)
	{
		boundary->Render(game_window);
		ball->Render(game_window);
		player1->Render(game_window);
		player2->Render(game_window);
		ui_service->Render(game_window);
	}
	void GameplayManager::Update()
	{
		time_service->Update();

		ball->Update(player1,player2,time_service);

		player1->Update(event_manager->IsKeyPressed(Keyboard::W),
			event_manager->IsKeyPressed(Keyboard::S),time_service);

		player2->Update(event_manager->IsKeyPressed(Keyboard::Up),
			event_manager->IsKeyPressed(Keyboard::Down),time_service);
	}
}