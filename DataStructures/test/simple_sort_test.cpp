#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
#include "..\sort\simple_sort.h"

void test_simple_sort() {

	const size_t NMAX = 10;
	std::array<int, NMAX> data;
	for (auto& elm : data)
		elm = rand() % 1000;
	std::cout << "InsertSort test\n";
	std::cout << "Init array: ";
	std::copy(std::begin(data), std::end(data), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

	simpleSort::insertSort(&data[0], NMAX);
	
	std::cout << "After sort: ";
	std::copy(std::begin(data), std::end(data), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	/* ------------------------------------- */
	for (auto& elm : data)
		elm = rand() % 1000;
	std::cout << "SelectSort test\n";
	std::cout << "Init array: ";
	std::copy(std::begin(data), std::end(data), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

	simpleSort::selectSort(&data[0], NMAX);

	std::cout << "After sort: ";
	std::copy(std::begin(data), std::end(data), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	/* ------------------------------------- */
	for (auto& elm : data)
		elm = rand() % 1000;
	std::cout << "BubbleSort test\n";
	std::cout << "Init array: ";
	std::copy(std::begin(data), std::end(data), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

	simpleSort::bubbleSort(&data[0], NMAX);

	std::cout << "After sort: ";
	std::copy(std::begin(data), std::end(data), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

}

