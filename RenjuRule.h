#pragma once
#include "RenjuRule_Roll.h"
#include "MapControl.h"
#include "default_property.h"
using namespace RenjuRule;

namespace RenjuRule
{
	template<int map_y_size, int map_x_size>
	class Rule 
	{
	private:
		VictoryRoll_t<map_y_size, map_x_size> VictoryRoll;
		_3_3_Search_t<map_y_size, map_x_size> _3_3_Search;
		MapControl_t<map_y_size, map_x_size> MapControl;
	public:
		Rule()
		{
			static bool InstanceExist = false;
			if (InstanceExist)
			{
				assert("Rule에서 인스턴스가 2번 이상 생성되었습니다");
			}
			InstanceExist = true;
		}
	};
}