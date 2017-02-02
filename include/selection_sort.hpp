#include <algorithm>


// template <typename Iterator>
// void selection_sort(Iterator begin, Iterator end)
// {
// 	for (auto i = begin; i != end; ++i) {
// 		std::iter_swap(i, std::min_element(i, end));
// 	}
// }


template <typename Iterator>
void selection_sort(Iterator begin, Iterator end)
{
	for (auto i = begin; i != end; ++i) {
		auto min = i;
		for (auto j = i + 1; j != end; ++j) {
			if (*j < *min) {
				min = j;
			}
		}
		std::swap(*min, *i);
	}
}
