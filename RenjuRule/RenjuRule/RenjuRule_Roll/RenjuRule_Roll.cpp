#include "RenjuRule_Roll.h"

#include "craft_range.h"


/*
template<int size_y, int size_x>
bool VictoryRollByOneLine(bool arr[size_y][size_x], std::pair<int, int> &parXY, std::pair<int, int>& d) // 한 라인에 한정해서 승리 판단함
{
	auto [yDirection, xDirection] = d;
간선이 끊길 때까지 방향 쪽으로 나아감
간선이 끊길 때까지 방향의 반대쪽으로 나아감
나아간 수는 i. i가 5와 같으면 승리판정 
	int tempX = pointX;
	int tempY = pointY;
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
}

template<int size_y, int size_x>
bool VictoryRoll(int arr[size_y][size_x], std::pair<int, int> &parYX) //가능한 모든 라인에 대해 승리 판단함
{
	// 1, 1은 오른쪽 위 대각선 -1, 1 은 오른쪽 아래 대각선 0, -1은 왼쪽으로 그은 수선 1, 0은 위로 그은 수선
	std::pair<int, int> d[4] = { {1, 1}, {-1, 1}, {0, -1}, {1, 0} };
	bool ret = true;
	//모든 방향에 대한 VictoryRollByOneLine이 참이라면 true를 리턴 아니라면 false를 리턴
	for (int i = 0; i < 4; i++)
	{
		ret = ret && VictoryRollByOneLine<size_y, size_x>(arr, parYX, d[i]);
	}
	return ret;
}
*/

