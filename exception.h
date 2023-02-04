#pragma once
#include <string>

namespace craft
{
	class exception
	{
		std::string errorMsg;
	public:
		exception(std::string param)
			: errorMsg(param)
		{
		}
		auto get_error() { return errorMsg; }
	};
}