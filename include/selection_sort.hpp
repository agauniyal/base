#include <algorithm>
#include <functional>

namespace base {
namespace selection {

	template <typename Iterator, typename Compare = std::less<>>
	void sort(Iterator begin, Iterator end, Compare comp = Compare())
	{
		for (auto i = begin; i != end; ++i) {
			auto min = i;
			for (auto j = i + 1; j != end; ++j) {
				if (comp(*j, *min)) {
					min = j;
				}
			}
			std::swap(*min, *i);
		}
	}
}
}
