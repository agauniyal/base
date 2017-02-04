#include <gtest/gtest.h>
#include "bubble_sort.hpp"
#include <random>
#include <functional>

TEST(bubble_sort, ascending)
{
	std::random_device rnd_device;
	std::mt19937 m_engine(rnd_device());
	std::uniform_int_distribution<int> dist(1, 100000);
	auto gen = std::bind(dist, m_engine);

	std::vector<int> v1(1000);
	std::generate(v1.begin(), v1.end(), gen);
	auto v2 = v1;

	base::bubble::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());

	ASSERT_EQ(v1, v2);
}


TEST(bubble_sort, descending)
{
	std::random_device rnd_device;
	std::mt19937 m_engine(rnd_device());
	std::uniform_int_distribution<int> dist(1, 52);
	auto gen = std::bind(dist, m_engine);

	std::vector<int> v1(1000);
	std::generate(v1.begin(), v1.end(), gen);
	auto v2 = v1;

	auto desc = [](auto a, auto b) { return a > b; };

	base::bubble::sort(v1.begin(), v1.end(), desc);
	std::sort(v2.begin(), v2.end(), desc);

	ASSERT_EQ(v1, v2);
}
