#include <algorithm>
#include <iterator>
#include <vector>

namespace base {
namespace merge {

	template <typename Iterator, typename Compare>
	void mergeBack(Iterator begin, Iterator mid, Iterator end, Compare comp)
	{
		typedef typename std::iterator_traits<Iterator>::value_type ElemType;
		std::vector<ElemType> left, right;

		left.reserve(mid - begin);
		right.reserve(end - mid);

		std::move(begin, mid, std::back_inserter(left));
		std::move(mid, end, std::back_inserter(right));

		size_t j = 0, k = 0;
		auto i = begin;
		for (; i != end && j < left.size() && k < right.size(); ++i) {
			*i = std::move(comp(left[j], right[k]) ? left[j++] : right[k++]);
		}

		while (j < left.size()) {
			*(i++) = std::move(left[j++]);
		}

		while (k < right.size()) {
			*(i++) = std::move(right[k++]);
		}
	}


	template <typename Iterator, typename Compare = std::less<>>
	void sort(Iterator begin, Iterator end, Compare comp = Compare())
	{
		if (end - begin > 1) {
			const auto middle = (end - begin) / 2;
			merge::sort(begin, begin + middle, comp);
			merge::sort(begin + middle, end, comp);
			mergeBack(begin, begin + middle, end, comp);
		}
	}
}
}
