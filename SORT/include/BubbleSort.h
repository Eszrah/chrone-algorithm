#pragma once

#include <functional>

namespace CHRONE::ALGORITHM
{

template<
	class It,
	class Comp>
constexpr void	BubbleSortImpl(It begin, It end, Comp& comp)
{
	while(end != begin)
	{
		It	lastSwapNextIt{ begin };

		for (It current{ begin }, next{ std::next(begin) }; 
			next != end; ++current, ++next)
		{
			if(comp(*next, *current))
			{
				std::swap(*current, *next);
				lastSwapNextIt = next;
			}
		}

		end = lastSwapNextIt;
	}
}

template<
	class It>
constexpr void	BubbleSort(It begin, It end)
{
	auto	lessPred = std::less<>();
	BubbleSortImpl(begin, end, lessPred);
}

template<
	class It,
	class Comp>
constexpr void	BubbleSort(It begin, It end, Comp comp)
{
	BubbleSortImpl(begin, end, comp);
}
}