#pragma once
#include "../Gameplay/Ball.h"
#include "../Gameplay/Paddle.h"
#include "../../Header/Events/EventManager.h"
#include "../../Header/Boundaries/Boundary.h"
#include "../../Header/Utility/TimeService.h"
#include "../../Header/UI/UIService.h"

using namespace sf;
using namespace Events;
using namespace Boundaries;
using namespace Utility;
using namespace UI;

namespace Gameplay
{
	class GameplayManager
	{
	private:
		TimeService* time_service;
		EventManager* event_manager;
		UIService* ui_service;
		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;

		float player2_position_x = 1216.0f;
		float player2_position_y = 300.0f;

		Ball* ball;
		Paddle* player1;
		Paddle* player2;
		Boundary* boundary;
		void Initialize();
	public:
		GameplayManager(EventManager* manager);
		void Update();
		void Render(RenderWindow* game_window);
		void UpdateScore();
		void ResetPlayers();
	};
}