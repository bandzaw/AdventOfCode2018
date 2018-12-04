#include <iostream>
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/istream_range.hpp>

int main()
{
	std::cout << "Day1 part1:\n";

	using namespace ranges;
	std::cout << accumulate(istream_range<int>(std::cin), 0) << '\n';
}