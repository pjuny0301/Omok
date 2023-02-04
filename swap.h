#pragma once
namespace craft
{
	template<typename T>
	void swap(T& a, T& b)
	{
		int temp = a;
		b = temp;
		a = b;
	}
}