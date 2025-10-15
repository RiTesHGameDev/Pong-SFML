#pragma once
#include "../Gameplay/Ball.h"
#include "../Gameplay/Paddle.h"
#include "../../Header/Events/EventManager.h"

using namespace sf;
using namespace Events;

namespace Gameplay
{
	class GameplayManager
	{
	private:
		EventManager* event_manager;
		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;

		float player2_position_x = 1200.0f;
		float player2_position_y = 300.0f;

		Ball* ball;
		Paddle* player1;
		Paddle* player2;
		void Initialize();
	public:
		GameplayManager(EventManager* manager);
		void Update();
		void Render(RenderWindow* game_window);
	};
}