#include <gtest/gtest.h>
#include "selection_sort.hpp"
#include <random>
#include <functional>

TEST(selection_sort, ascending)
{
	std::random_device rnd_device;
	std::mt19937 m_engine(rnd_device());
	std::uniform_int_distribution<int> dist(1, 100000);
	const auto gen = std::bind(dist, m_engine);

	std::vector<int> v1(1000);
	std::generate(v1.begin(), v1.end(), gen);
	auto v2 = v1;

	base::selection::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());

	ASSERT_EQ(v1, v2);
}


TEST(selection_sort, descending)
{
	std::random_device rnd_device;
	std::mt19937 m_engine(rnd_device());
	std::uniform_int_distribution<int> dist(1, 52);
	const auto gen = std::bind(dist, m_engine);

	std::vector<int> v1(1000);
	std::generate(v1.begin(), v1.end(), gen);
	auto v2 = v1;

	const auto desc = [](auto a, auto b) { return a > b; };

	base::selection::sort(v1.begin(), v1.end(), desc);
	std::sort(v2.begin(), v2.end(), desc);

	ASSERT_EQ(v1, v2);
}


TEST(selection_sort, noElement)
{
	std::vector<int> v1;
	const auto desc = [](auto a, auto b) { return a > b; };
	base::selection::sort(v1.begin(), v1.end(), desc);

	EXPECT_EQ(0, v1.size());
}


TEST(selection_sort, singleElement)
{
	std::vector<int> v1{ 0 };
	const auto v2   = v1;
	const auto desc = [](auto a, auto b) { return a > b; };
	base::selection::sort(v1.begin(), v1.end(), desc);

	ASSERT_EQ(v2, v1);
}
