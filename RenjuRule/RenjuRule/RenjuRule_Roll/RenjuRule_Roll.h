#pragma once

#include<utility>
#include<assert.h>
#include "default_property.h"
namespace RenjuRule
{
	template <int size_y, int size_x>
	class VictoryRoll_t
	{
	public:
		VictoryRoll_t()
		{
			static bool InstanceExist = false;
			if (InstanceExist)
			{
				assert("VictoryRoll_t 에서 인스턴스가 두 번 생성되었습니다");
			}
			InstanceExist = true;
		}
		bool operator ()(int arr[size_y][size_x], std::pair<int, int>& YX)
		{
			auto d[4] = { {1, 1}, {-1, 1}, {0, 1}, {1, 0} };
			bool ret = true;

			for (int i = 0; i < 4; i++)
			{
				ret = ret && VictoryRollByOneLine(arr, YX, d[i]);
			}
		}
	private:
		bool VictoryRollByOneLine(bool arr[size_y][size_x], std::pair<int, int>& YX, std::pair<int, int>& d) // 한 라인에 한정해서 승리 판단함
		{
			auto [yDirection, xDirection] = d;
			auto [tempY, tempX] = YX;
			/*
			간선이 끊길 때까지 방향 쪽으로 나아감
				간선이 끊길 때까지 방향의 반대쪽으로 나아감
				나아간 수는 i.i가 5와 같으면 승리판정
			*/

			int stoneNum = 0;
			while (arr[tempY][tempX])
			{
				tempY += yDirection;
				tempX += xDirection;
				stoneNum++;
			}
			tempX = pointX - xDirection; // 똑같은 곳을 다시 조사하면 중복되어 i 숫자가 1 늘어난다.
			tempY = pointY - yDirection;
			while (arr[tempY][tempX])
			{
				tempY -= yDirection;
				tempX -= xDirection;
				stoneNum++;
			}
			if (stoneNum == 5)
			{
				return true;
			}
			return false;
		};


	};

	template <int size_y, int size_x>
	class _3_3_Search_t
	{
	private:
	public:
		_3_3_Search_t()
		{
			static bool InstanceExist = false;
			if (InstanceExist)
			{
				assert("_3_3_Search_t 에서 인스턴스가 두 번 생성되었습니다");
			}
			InstanceExist = true;
		}

	private:
		std::pair<int, int> _3_3_pos; //33인 좌표 //side effect
	public:
		std::pair<int, int> operator ()(int arr[size_y][size_x], std::pair<int, int>& YX)
		{
			std::pair<int, int> d[4] = { {1, 1}, {-1, 1}, {0, -1}, {1, 0} };
			bool ret = true;

			for (int i = 0; i < 4; i++)
			{
				ret = ret && _3_3_SearchByStraightLine(arr, YX, d[i]); // 직선인 4 방향에 대해 33판정
				ret = ret && _3_3_RollByVerticalLine(arr, YX, d[i]); // 꺾은 4 방향에 대해 33판정
			}
			return ret;
		}

	private:
		bool _3_3_SearchByStraightLine(int arr[size_y][size_x], std::pair<int, int>& YX, std::pair<int, int>& d)
		{
			return isLineLength_3(arr, YX, d) && isLineLength_3(arr, YX, -1 * d); // 두 방향의 선의 길이가 모두 3이면 33 판정
		}

		bool isLineLength_3(int arr[size_y][size_x], std::pair<int, int>& YX, std::pair<int, int>& d)
		{
			auto [yDirection, xDirection] = d;
			auto [tempY, tempX] = YX;
			int i = 0;
			int stoneNum = 0;
			std::pair<int, int> retYX = { 0, 0 };
			while (i < 4)
			{
				if (arr[tempY][tempX])
				{
					stoneNum++;
				}
				else if (not arr[tempY][tempX])
				{
					retXY = { tempY, tempX };
				}
				tempY += yDirection;
				tempX += xDirection;
				i++;
			}

			if (stoneNum == 3)
			{
				return true;
			}
			return false;
		}

	private:
		bool _3_3_SearchByVerticalLine(int arr[size_y][size_x], std::pair<int, int>& YX, std::pair<int, int>& d)
		{
			return isLineLength_3(arr, YX, -1 * d) && isLineLength_3(arr, YX, getVerticalDir(d));
		}

		std::pair<int, int> getVerticalDir(std::pair<int, int>& Dir) // 수직한 방향 구함
		{
			if (Dir.first == 0 || Dir.second == 0 && not(Dir.first == 0 && Dir.second == 0))
			{
				swap(Dir.first, Dir.second);
			}
			else
			{
				Dir.first *= -1;
			}
		}
	};
}
