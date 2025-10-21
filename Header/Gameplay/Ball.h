#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Gameplay/Paddle.h"
#include "../../Header/Utility/TimeService.h"
#include "../../Header/Sounds/SoundManager.h"

using namespace sf;
using namespace std;
using namespace Utility;
using namespace Sounds;

namespace Gameplay
{
	enum class BallState
	{
		Idle,
		Moving
	};
	class Ball
	{
	private:
		Sprite pong_ball_sprite;
		Texture pong_ball_texture;
		string texture_path = "Assets/Textures/Ball.png";

		const float position_x = 615.0f;
		const float position_y = 335.0f;

		const float scale_x = 0.05f;
		const float scale_y = 0.05f;

		const float top_boundary = 20.0f;
		const float bottom_boundary = 700.0f;

		const float left_boundary = 0.0f;
		const float right_boundary = 1280.0f;

		const float center_position_x = 615.0f;
		const float center_position_y = 325.0f;

		float ball_speed = 100.0f;
		float speed_multiplier = 10.0f;

		float elapsed_delay_time = 0.0f;
		float delay_duration = 2.0f;

		bool had_left_collision = false;
		bool had_right_collision = false;

		Vector2f velocity = Vector2f(ball_speed, ball_speed);

		BallState current_state;

		void BallMove(TimeService* time_service);
		void LoadTexture();
		void Initialize();
		void UpdateDelayTime(float delta_Time);

	public:
		Ball();
		void Update(Paddle* player1,Paddle* player2,TimeService* time_service);
		void Render(RenderWindow* game_window);

		void HandlePaddleCollision(Paddle* player1, Paddle* player2);
		void HandleBoundaryCollision();
		void HandleOutOfBoundCollision();

		void Oncollision(Paddle* player1,Paddle* player2);
		void Reset();

		bool IsLeftCollisionOccured();
		void UpdateLeftCollisionState(bool value);

		bool IsRightCollisionOccured();
		void UpdateRightCollisionState(bool value);
	};
}