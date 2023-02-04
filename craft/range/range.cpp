
#include "range.h"
#include <utility>

using namespace craft;

bool craft::is_in(range&& target, range&& rangePar)
{
	bool firstConcept = rangePar.first <= target.first;
	bool secondConcept = target.second <= rangePar.second;
	return firstConcept && secondConcept;
}

bool craft::is_in(rangeElemType target, range&& rangePar)
{
	return rangePar.first <= target <= rangePar.second;
}

bool craft::is_out_of(range&& target, range&& rangePar)
{
	return not is_in(std::move(target), std::move(rangePar));
}

bool craft::is_out_of(rangeElemType var, range&& rangePar)
{
	return not is_in(var, std::move(rangePar));
}

bool craft::is_same_range(range&& par1, range&& par2)
{
	return (par1.first == par2.first) && (par1.second == par2.second);
}
