#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Boundaries
{
	class Boundary
	{
	private:
		RectangleShape top_boundary;
		RectangleShape bottom_boundary;
		RectangleShape left_boundary;
		RectangleShape right_boundary;
		RectangleShape center_line;

		const float horizontal_boundary_width = 1280.0f;
		const float horizontal_boundary_height = 20.0f;

		const float top_position_x = 0.0f;
		const float top_position_y = 0.0f;

		const float bottom_position_x = 0.0f;
		const float bottom_position_y = 700.0f;

		const float vertical_boundary_width = 20.0f;
		const float vertical_boundary_height = 720.0f;

		const float left_position_x = 0.0f;
		const float left_position_y = 0.0f;

		const float right_position_x = 1260.0f;
		const float right_position_y = 0.0f;

		const float center_line_width = 10.0f;
		const float center_line_height = 680.0f;

		const float center_line_position_x = 640.0f;
		const float center_line_position_y = 20.0f;

		const Color boundary_color = Color::Blue;
		const Color center_line_color = Color::White;

		void CreateTopBoundary();
		void CreateBottomBoundary();
		void CreateLeftBoundary();
		void CreateRightBoundary();
		void CreateCenterLine();

	public:
		Boundary();
		void Render(RenderWindow* game_window);
	};
}
