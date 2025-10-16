#include "../../Header/Boundaries/Boundary.h"

namespace Boundaries
{
	Boundary::Boundary()
	{
		CreateTopBoundary();
		CreateLeftBoundary();
		CreateRightBoundary();
		CreateBottomBoundary();
		CreateCenterLine();
	}
	void Boundary::CreateTopBoundary()
	{
		top_boundary.setSize(Vector2f(horizontal_boundary_width, horizontal_boundary_height));
		top_boundary.setPosition(top_position_x,top_position_y);
		top_boundary.setFillColor(boundary_color);
	}
	void Boundary::CreateBottomBoundary()
	{
		bottom_boundary.setSize(Vector2f(horizontal_boundary_width, horizontal_boundary_height));
		bottom_boundary.setPosition(bottom_position_x, bottom_position_y);
		bottom_boundary.setFillColor(boundary_color);
	}
	void Boundary::CreateLeftBoundary()
	{
		left_boundary.setSize(Vector2f(vertical_boundary_width, vertical_boundary_height));
		left_boundary.setPosition(left_position_x, left_position_y);
		left_boundary.setFillColor(boundary_color);
	}
	void Boundary::CreateRightBoundary()
	{
		right_boundary.setSize(Vector2f(vertical_boundary_width, vertical_boundary_height));
		right_boundary.setPosition(right_position_x, right_position_y);
		right_boundary.setFillColor(boundary_color);
	}
	void Boundary::CreateCenterLine()
	{
		center_line.setSize(Vector2f(center_line_width, center_line_height));
		center_line.setPosition(center_line_position_x, center_line_position_y);
		center_line.setFillColor(center_line_color);
	}
	void Boundary::Render(RenderWindow* game_window)
	{
		game_window->draw(top_boundary);
		game_window->draw(bottom_boundary);
		game_window->draw(left_boundary);
		game_window->draw(right_boundary);
		game_window->draw(center_line);
	}
}