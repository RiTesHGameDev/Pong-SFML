#pragma once
#include "../Gameplay/Ball.h"
#include "../Gameplay/Paddle.h"

using namespace sf;

namespace Gameplay
{
	class GameplayManager
	{
	private:
		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;

		float player2_position_x = 1210.0f;
		float player2_position_y = 300.0f;

		Ball* ball;
		Paddle* player1;
		Paddle* player2;
		void Initialize();
	public:
		GameplayManager();
		void Update();
		void Render(RenderWindow* game_window);
	};
}