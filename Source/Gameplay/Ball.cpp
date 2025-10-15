#include "../../Header/Gameplay/Ball.h"

using namespace sf;

namespace Gameplay
{
	Ball::Ball()
	{
		LoadTexture();
		InitializeVariables();
	}
	void Ball::Update()
	{

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
	void Ball::InitializeVariables()
	{
		pong_ball_sprite.setTexture(pong_ball_texture);
		pong_ball_sprite.setScale(scale_x, scale_y);
		pong_ball_sprite.setPosition(position_x, position_y);
	}
}