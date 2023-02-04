#pragma once
#include <utility>
#include "exception.h"
using namespace craft;

template<int size_y, int size_x>
class MapControl_t
{
	bool data[size_y][size_x] = { false };

	typedef int data_idx_type;

public:
	MapControl_t()
	{
		static bool InstanceExist = false;
		if (InstanceExist)
		{
			assert("MapControl_t 에서 인스턴스가 두 번 이상 생성되었습니다");
		}
		InstanceExist = true;
	}

	void set_true(std::pair<data_idx_type, data_idx_type> param)
	{
		auto [yIdx, xIdx] = param;
		if (yIdx > size_y || xIdx > size_x) { throw exception("MapControl_t::set_true에 범위를 넘는 값이 전달되었습니다"); }
		data[yIdx][xIdx] = true;
	}
	void set_false(std::pair<data_idx_type, data_idx_type> param)
	{
		auto [yIdx, xIdx] = param;
		if (yIdx > size_y || xIdx > size_x) { throw exception("MapControl_t::set_true에 범위를 넘는 값이 전달되었습니다"); }
		data[yIdx][xIdx] = false;
	}
	bool[size_y][size_x] get_data()
	{
		static bool buf[size_y][size_x] = { false };
		for (int i = 0; i < size_y; i++)
		{
			for (int j = 0; j < size_x; j++)
			{
				buf[i][j] = data[i][j];
			}
		}
		return buf;
	}
};