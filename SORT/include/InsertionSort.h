#pragma once

#include <functional>

namespace CHRONE::ALGORITHM
{

template<
	class It,
	class Comp>
constexpr void	InsertionSortImpl(It begin, It end, Comp& comp)
{
	if (begin == end) { return; }

	It	sortedRange[2]{ begin , std::next(begin) };

	while (sortedRange[1] != end)
	{
		decltype(std::distance(sortedRange[0], sortedRange[1])) sortedRangeSize{ 
			std::distance(sortedRange[0], sortedRange[1]) };

		It	currentInsertedIt{ std::next(sortedRange[1]) };
		It	currentCompIt{ sortedRange[1] };

		while (sortedRangeSize-- != 0)
		{
			currentInsertedIt--; currentCompIt--;
			if (!comp(*currentInsertedIt, *currentCompIt)) { break; }
			std::swap(*currentInsertedIt, *currentCompIt);
		}

		++sortedRange[1];
	}
}

template<
	class It>
constexpr void	InsertionSort(It begin, It end)
{
	auto	lessPred = std::less<>();
	InsertionSortImpl(begin, end, lessPred);
}


template<
	class It,
	class Comp>
constexpr void	InsertionSort(It begin, It end, Comp& comp)
{
	InsertionSortImpl(begin, end, comp);
}

}