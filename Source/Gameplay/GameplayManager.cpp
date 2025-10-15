#include "../../Header/Gameplay/GameplayManager.h"

using namespace sf;

namespace Gameplay
{
	GameplayManager::GameplayManager()
	{
		Initialize();
	}
	void GameplayManager::Initialize()
	{
		ball = new Ball();
		player1 = new Paddle(player1_position_x, player1_position_y);
		player2 = new Paddle(player2_position_x, player2_position_y);
	}
	void GameplayManager::Render(RenderWindow* game_window)
	{
		ball->Render(game_window);
		player1->Render(game_window);
		player2->Render(game_window);
	}
}