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
				assert("VictoryRoll_t ���� �ν��Ͻ��� �� �� �����Ǿ����ϴ�");
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
		bool VictoryRollByOneLine(bool arr[size_y][size_x], std::pair<int, int>& YX, std::pair<int, int>& d) // �� ���ο� �����ؼ� �¸� �Ǵ���
		{
			auto [yDirection, xDirection] = d;
			auto [tempY, tempX] = YX;
			/*
			������ ���� ������ ���� ������ ���ư�
				������ ���� ������ ������ �ݴ������� ���ư�
				���ư� ���� i.i�� 5�� ������ �¸�����
			*/

			int stoneNum = 0;
			while (arr[tempY][tempX])
			{
				tempY += yDirection;
				tempX += xDirection;
				stoneNum++;
			}
			tempX = pointX - xDirection; // �Ȱ��� ���� �ٽ� �����ϸ� �ߺ��Ǿ� i ���ڰ� 1 �þ��.
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
				assert("_3_3_Search_t ���� �ν��Ͻ��� �� �� �����Ǿ����ϴ�");
			}
			InstanceExist = true;
		}

	private:
		std::pair<int, int> _3_3_pos; //33�� ��ǥ //side effect
	public:
		std::pair<int, int> operator ()(int arr[size_y][size_x], std::pair<int, int>& YX)
		{
			std::pair<int, int> d[4] = { {1, 1}, {-1, 1}, {0, -1}, {1, 0} };
			bool ret = true;

			for (int i = 0; i < 4; i++)
			{
				ret = ret && _3_3_SearchByStraightLine(arr, YX, d[i]); // ������ 4 ���⿡ ���� 33����
				ret = ret && _3_3_RollByVerticalLine(arr, YX, d[i]); // ���� 4 ���⿡ ���� 33����
			}
			return ret;
		}

	private:
		bool _3_3_SearchByStraightLine(int arr[size_y][size_x], std::pair<int, int>& YX, std::pair<int, int>& d)
		{
			return isLineLength_3(arr, YX, d) && isLineLength_3(arr, YX, -1 * d); // �� ������ ���� ���̰� ��� 3�̸� 33 ����
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

		std::pair<int, int> getVerticalDir(std::pair<int, int>& Dir) // ������ ���� ����
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