#pragma once
#include <utility>
namespace craft
{
	namespace //Functions Declaration
	{
		class range;
		typedef int rangeElemType;
		bool is_in(range&&, range&&);
		bool is_in(rangeElemType, range&&);
		bool is_out_of(range&&, range&&);
		bool is_out_of(rangeElemType, range&&);
		bool is_same_range(range&&, range&&);
	}
		class range
		{
		private:
			friend bool is_in(range&&, range&&);
			friend bool is_in(rangeElemType, range&&);
			friend bool is_out_of(range&&, range&&);
			friend bool is_out_of(rangeElemType, range&&);
			friend bool is_same_range(range&&, range&&);
			rangeElemType first;
			rangeElemType second;
		public:
			range(int first, int second)
			{
				this->first = first;
				this->second = second;
			}
		};
}
