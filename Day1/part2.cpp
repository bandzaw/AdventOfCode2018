#include <iostream>
#include <vector>
#include <unordered_set>
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/istream_range.hpp>
#include <range/v3/view/cycle.hpp>
#include <range/v3/view/partial_sum.hpp>

int main()
{
	std::cout << "Day1 part2:\n";

	using namespace ranges;

	std::unordered_set<int> vals;
    auto input = istream_range<int>(std::cin) | to_vector;
	auto cyclic_input = input | ranges::view::cycle;
	auto acc_cyc_inp = cyclic_input | view::partial_sum(std::plus<>());
	for (const auto& v : acc_cyc_inp)
	{
		if (!vals.insert(v).second)
		{
			std::cout << "Frequency " << v << " appeared twice!\n";
			break;
		}
	}
}