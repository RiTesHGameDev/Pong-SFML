#include "../../Header/Gameplay/Ball.h"

using namespace sf;

namespace Gameplay
{
	Ball::Ball()
	{
		LoadTexture();
		CreateBall();
	}
	void Ball::Update(Paddle* player1,Paddle* player2)
	{
		BallMove();
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
	void Ball::CreateBall()
	{
		pong_ball_sprite.setTexture(pong_ball_texture);
		pong_ball_sprite.setScale(scale_x, scale_y);
		pong_ball_sprite.setPosition(position_x, position_y);
	}
	void Ball::BallMove()
	{
		pong_ball_sprite.move(velocity);
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
			Reset();
		}
		else if (ball_bounds.left + ball_bounds.width >= right_boundary)
		{
			Reset();
		}
	}
	void Ball::Reset()
	{
		pong_ball_sprite.setPosition(center_position_x, center_position_y);
		velocity = Vector2f(ball_speed, ball_speed);
	}
}