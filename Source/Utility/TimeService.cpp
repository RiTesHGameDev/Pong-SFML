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
		int delta = chrono::duration_cast<chrono::microseconds>
			(chrono::steady_clock::now() - previous_time).count();
		return static_cast<float>(delta) / 1000000.0f;
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