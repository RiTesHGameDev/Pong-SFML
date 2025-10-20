#include "../../Header/Utility/TimeService.h"

namespace Utility
{
	void TimeService::Initialize()
	{
		previous_time = chrono::steady_clock::now();
		delta_time = 0;
	}
	float TimeService::CalculateDeltaTime()
	{
		auto now = chrono::steady_clock::now();
		auto time_diff = now - previous_time;
		previous_time = now;
		auto delta_seconds = chrono::duration_cast<chrono::duration<float>>(time_diff);
		return delta_seconds.count();
	}
	void TimeService::UpdateDeltaTime()
	{
		delta_time = CalculateDeltaTime();
		UpdatePreviousTime();
	}

	void TimeService::UpdatePreviousTime()
	{
		previous_time = std::chrono::steady_clock::now();
	}

	void TimeService::Update()
	{
		UpdateDeltaTime();
	}
	float TimeService::GetDeltaTime()
	{
		return delta_time;
	}
}