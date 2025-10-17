#pragma once
#include <chrono>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace Utility
{
	class TimeService
	{
	private:
		chrono::steady_clock::time_point previous_time;
		float delta_time;

		void UpdateDeltaTime();
		float CalculateDeltaTime();
		void UpdatePreviousTime();
	public:
		void Initialize();
		void Update();
		float GetDeltaTime();
	};
}