#include <algorithm>
#include <functional>

namespace base {
namespace bubble {

	template <typename Iterator, typename Compare = std::less<>>
	void sort(Iterator begin, Iterator end, Compare comp = Compare())
	{
		if (end - begin < 1) {
			return;
		}

		for (auto i = begin; i != end; ++i) {
			bool swapped = false;
			for (auto j = end - 1; j != i; --j) {
				if (comp(*j, *(j - 1))) {
					std::swap(*j, *(j - 1));
					swapped = true;
				}
			}
			if (!swapped) break;
		}
	}
}
}
