#include "selection_sort.hpp"
#include <vector>
#include <iostream>
#include <random>
#include <functional>

int main()
{
	std::random_device rnd_device;
	std::mt19937 m_engine(rnd_device());
	std::uniform_int_distribution<int> dist(1, 52);
	auto gen = std::bind(dist, m_engine);

	std::vector<int> v(10);
	std::generate(v.begin(), v.end(), gen);

	for (auto &i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	selection_sort(v.begin(), v.end());

	for (auto &i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
