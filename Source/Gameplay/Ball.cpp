#include "../../Header/Gameplay/Ball.h"

using namespace sf;

namespace Gameplay
{
	Ball::Ball()
	{
		LoadTexture();
		Initialize();
		Reset();
	}
	void Ball::Update(Paddle* player1,Paddle* player2,TimeService* time_service)
	{
		BallMove(time_service);
		Oncollision(player1,player2);
	}
	void Ball::Render(RenderWindow* game_window)
	{
		game_window->draw(pong_ball_sprite);
	}
	void Ball::LoadTexture()
	{
		if (!pong_ball_texture.loadFromFile(texture_path))
		{
			throw runtime_error("Failed to load ball texture!");
		}
		pong_ball_texture.setSmooth(true);
	}
	void Ball::Initialize()
	{
		pong_ball_sprite.setTexture(pong_ball_texture);
		pong_ball_sprite.setScale(scale_x, scale_y);
		pong_ball_sprite.setPosition(position_x, position_y);
		current_state = BallState::Idle;
	}
	void Ball::BallMove(TimeService* time_service)
	{
		UpdateDelayTime(time_service->GetDeltaTime());
		if (current_state != BallState::Moving)
			return;

		pong_ball_sprite.move(velocity * time_service->GetDeltaTime() * speed_multiplier);
	}
	void Ball::Oncollision(Paddle* player1, Paddle* player2)
	{
		HandlePaddleCollision(player1, player2);
		HandleBoundaryCollision();
		HandleOutOfBoundCollision();

	}
	void Ball::HandlePaddleCollision(Paddle* player1,Paddle* player2)
	{
		//Getting the sprite
		const Sprite& player1_paddle = player1->GetPaddleSprite();
		const Sprite& player2_paddle = player2->GetPaddleSprite();

		//check their bounds
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
		FloatRect player1_bounds = player1_paddle.getGlobalBounds();
		FloatRect player2_bounds = player2_paddle.getGlobalBounds();

		//Handle collisions
		if (ball_bounds.intersects(player1_bounds) && velocity.x < 0)
		{
			velocity.x = -velocity.x;
		}
		if (ball_bounds.intersects(player2_bounds) && velocity.x > 0)
		{
			velocity.x = -velocity.x;
		}
	}
	void Ball::HandleBoundaryCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if ((ball_bounds.top <= top_boundary && velocity.y < 0) ||
			(ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0))
		{
			velocity.y = -velocity.y;
		}
	}
	void Ball::HandleOutOfBoundCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if (ball_bounds.left <= left_boundary)
		{
			UpdateLeftCollisionState(true);
			Reset();
		}
		else if (ball_bounds.left + ball_bounds.width >= right_boundary)
		{
			UpdateRightCollisionState(true);
			Reset();
		}
	}
	void Ball::Reset()
	{
		pong_ball_sprite.setPosition(center_position_x, center_position_y);
		velocity = Vector2f(0.0f, 0.0f);
		current_state = BallState::Idle;
		elapsed_delay_time = 0.0f;
	}
	void Ball::UpdateDelayTime(float delta_time)
	{
		if (current_state == BallState::Idle)
		{
			
			elapsed_delay_time += delta_time;

			if (elapsed_delay_time >= delay_duration)
			{
				current_state = BallState::Moving;
				velocity = Vector2f(ball_speed, ball_speed);
			}
			else
			{
				velocity = Vector2f(0.0f, 0.0f);
				return;
			}
		}
	}
	bool Ball::IsLeftCollisionOccured()
	{
		return had_left_collision;
	}
	bool Ball::IsRightCollisionOccured()
	{
		return had_right_collision;
	}
	void Ball::UpdateLeftCollisionState(bool value)
	{
		had_left_collision = value;
	}
	void Ball::UpdateRightCollisionState(bool value)
	{
		had_right_collision = value;
	}
}