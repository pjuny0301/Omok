#include "RenjuRule_Roll.h"

#include "craft_range.h"


/*
template<int size_y, int size_x>
bool VictoryRollByOneLine(bool arr[size_y][size_x], std::pair<int, int> &parXY, std::pair<int, int>& d) // �� ���ο� �����ؼ� �¸� �Ǵ���
{
	auto [yDirection, xDirection] = d;
������ ���� ������ ���� ������ ���ư�
������ ���� ������ ������ �ݴ������� ���ư�
���ư� ���� i. i�� 5�� ������ �¸����� 
	int tempX = pointX;
	int tempY = pointY;
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
}

template<int size_y, int size_x>
bool VictoryRoll(int arr[size_y][size_x], std::pair<int, int> &parYX) //������ ��� ���ο� ���� �¸� �Ǵ���
{
	// 1, 1�� ������ �� �밢�� -1, 1 �� ������ �Ʒ� �밢�� 0, -1�� �������� ���� ���� 1, 0�� ���� ���� ����
	std::pair<int, int> d[4] = { {1, 1}, {-1, 1}, {0, -1}, {1, 0} };
	bool ret = true;
	//��� ���⿡ ���� VictoryRollByOneLine�� ���̶�� true�� ���� �ƴ϶�� false�� ����
	for (int i = 0; i < 4; i++)
	{
		ret = ret && VictoryRollByOneLine<size_y, size_x>(arr, parYX, d[i]);
	}
	return ret;
}
*/

