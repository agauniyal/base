#include <algorithm>
#include <functional>

namespace base {
namespace insertion {

	template <typename Iterator, typename Compare = std::less<>>
	void sort(Iterator begin, Iterator end, Compare comp = Compare())
	{
		for (auto i = begin + 1; i != end; ++i) {
			auto key = *i;
			auto j   = i - 1;
			while (j != begin - 1 && comp(key, *j)) {
				*(j + 1) = *j;
				--j;
			}
			*(j + 1) = key;
		}
	}
}
}
