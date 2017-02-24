#include <algorithm>
#include <functional>

namespace base {
namespace heap {

	template <typename Iterator, typename Compare>
	void maxHeapify(Iterator current, Iterator begin, Iterator end,
	                Compare comp)
	{
		if (current < begin) {
			return;
		}

		const auto d     = std::distance(begin, current);
		const auto left  = (d != 0) ? (begin + ((d + 1) * 2) - 1) : (begin + 1);
		const auto right = (d != 0) ? (begin + ((d + 1) * 2)) : (begin + 2);

		auto largest = current;
		if (left < end && comp(*current, *left)) {
			largest = left;
		}
		if (right < end && comp(*largest, *right)) {
			largest = right;
		}
		if (largest != current) {
			std::swap(*current, *largest);
			maxHeapify(largest, begin, end, comp);
		}
	}


	template <typename Iterator, typename Compare = std::less<>>
	void sort(Iterator begin, Iterator end, Compare comp = Compare())
	{
		if (end - begin < 1) {
			return;
		}

		const auto mid = (end - begin) / 2;
		for (auto i = begin + mid; i != begin - 1; --i) {
			maxHeapify(i, begin, end, comp);
		}

		for (auto i = end - 1; i != begin; --i) {
			std::swap(*begin, *i);
			maxHeapify(begin, begin, i, comp);
		}
	}
}
}
