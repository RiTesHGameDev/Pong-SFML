#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Gameplay/Paddle.h"

using namespace sf;
using namespace std;

namespace Gameplay
{
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

		float ball_speed = 0.5f;
		Vector2f velocity = Vector2f(ball_speed, ball_speed);

		void BallMove();
		void LoadTexture();
		void CreateBall();
	public:
		Ball();
		void Update(Paddle* player1,Paddle* player2);
		void Render(RenderWindow* game_window);
		void HandlePaddleCollision(Paddle* player1, Paddle* player2);
		void HandleBoundaryCollision();
		void HandleOutOfBoundCollision();
		void Oncollision(Paddle* player1,Paddle* player2);
		void Reset();
	};
}