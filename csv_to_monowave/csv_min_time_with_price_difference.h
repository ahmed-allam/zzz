#ifndef CSV_MIN_TIME_WITH_PRICE_DIFFERENCE
#define CSV_MIN_TIME_WITH_PRICE_DIFFERENCE

#include "csv_time_bid_ask_difference.h"
#include <algorithm> //for min max

//21-12-2021
//#include "../Worker.h"
class Worker;
class csv_min_time_with_price_difference :public csv_time_bid_ask_difference
{
public:
	//default constructor
	csv_min_time_with_price_difference();
	csv_min_time_with_price_difference(Worker*);

	//members for csv_min_time_with_price_difference	
public:
	//19-12-2020
	std::vector<int> bidPrice_difference_absolute_sorted_epochpartTime_difference_zero;
	std::vector<int> bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_original_indices;
	std::vector<size_t> bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_original_indices_resorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_local_indices_sorted;
	std::vector<int> bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted_unique;


	std::vector<int> bidPrice_difference_absolute_sorted_tickpartTime_difference_zero;
	std::vector<int> bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_original_indices;
	std::vector<size_t> bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_original_indices_resorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_local_indices_sorted;
	std::vector<int> bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted_unique;

	std::vector<int> bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero;
	std::vector<int> bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_original_indices;
	std::vector<size_t> bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_original_indices_resorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_local_indices_sorted;
	std::vector<int> bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted_unique;


	std::vector<int> bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero;
	std::vector<int> bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_original_indices;
	std::vector<size_t> bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_original_indices_resorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_local_indices_sorted;
	std::vector<int> bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted_unique;


	std::vector<int> bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero;
	std::vector<int> bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_original_indices;
	std::vector<size_t> bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_original_indices_resorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_local_indices_sorted;
	std::vector<int> bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted_unique;


	std::vector<int> bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero;
	std::vector<int> bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_original_indices;
	std::vector<size_t> bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_original_indices_resorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_local_indices_sorted;
	std::vector<int> bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted_unique;

	std::vector<int> bidPrice_difference_absolute_sorted_epochpartTime_difference_last;
	std::vector<int> bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_epochpartTime_difference_last_original_indices;
	std::vector<size_t> bidPrice_difference_absolute_sorted_epochpartTime_difference_last_original_indices_resorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_epochpartTime_difference_last_local_indices_sorted;
	std::vector<int> bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted_unique;


	std::vector<int> bidPrice_difference_absolute_sorted_tickpartTime_difference_last;
	std::vector<int> bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_tickpartTime_difference_last_original_indices;
	std::vector<size_t> bidPrice_difference_absolute_sorted_tickpartTime_difference_last_original_indices_resorted;
	std::vector<size_t> bidPrice_difference_absolute_sorted_tickpartTime_difference_last_local_indices_sorted;
	std::vector<int> bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted_unique;

	std::vector<size_t> epochpartTime_difference_sorted_original_indices;
	std::vector<int> epochpartTime_difference_sorted;
	std::vector<int> epochpartTime_difference_sorted_unique;

	std::vector<size_t> tickpartTime_difference_sorted_original_indices;
	std::vector<int> tickpartTime_difference_sorted;
	std::vector<int> tickpartTime_difference_sorted_unique;


	int epochpartTime_difference_min_zero,
		epochpartTime_difference_min_above_zero,
		epochpartTime_difference_min_without_zero,
		epochpartTime_difference_min_last,
		epochpartTime_difference_min,
		epochpartTime_difference_max_zero,
		epochpartTime_difference_max_above_zero,
		epochpartTime_difference_max_without_zero,
		epochpartTime_difference_max_last,
		epochpartTime_difference_max;

	int tickpartTime_difference_min_zero,
		tickpartTime_difference_min_above_zero,
		tickpartTime_difference_min_without_zero,
		tickpartTime_difference_min_last,
		tickpartTime_difference_min,
		tickpartTime_difference_max_zero,
		tickpartTime_difference_max_above_zero,
		tickpartTime_difference_max_without_zero,
		tickpartTime_difference_max_last,
		tickpartTime_difference_max;

	//std::vector<long long> tickTime_difference;

	std::vector<size_t> bidPrice_difference_absolute_original_indices;
	//std::vector<unsigned int> bidPrice_difference_absolute_original_indices;//>>>>>9-9-2022

	std::vector<int> bidPrice_difference_absolute_sorted;
	std::vector<int> bidPrice_difference_absolute_sorted_unique;
	std::vector<int>::iterator it;
	//19-12-2020
	int bidPrice_difference_absolute_min_zero,
		bidPrice_difference_absolute_min_above_zero,
		bidPrice_difference_absolute_min_without_zero,
		bidPrice_difference_absolute_max;

	//24-12-2020
	int bidPrice_timeunit, bidPrice_priceunit;
	//25-12-2020
	//calculate number of time and price units for each tick to tick price difference
	std::vector<float> bidPrice_difference_tickpartTime_difference_time_units;
	std::vector<float> bidPrice_difference_price_units;
public:
	//I will make vector containing indices sorted ascendingly
	void get_bidPrice_difference_absolute_original_indices();
	//then I will sort price differences
	void get_sort_price_differences();
	//get unique values of price difference absolute
	void get_unique_values_price_difference_absolute();

	//getting range of 1st element in unique if it = zero in bidPrice_difference_absolute_sorted vector
	void get_range_of_first_element_in_unique_equalling_zero();
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds_zero;
	//first we make vector of time differences for range of zero using original indices
	void get_time_differences_range_of_zero_using_original_indices();
	//then we order time vectors ascendingly
	void get_order_time_vectors_ascendingly_epochpartTime_zero();
	void get_order_time_vectors_ascendingly_tickpartTime_zero();
	//---------------------------------------------------------------------------------------
			
	//getting range of 1st element"not equalling zero" in unique having 0
	void get_range_of_first_element_above_zero_in_unique_having_zero();
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds_with_zero;
	//first we make vector of time differences for range of above zero using original indices
	void get_time_differences_range_of_first_element_above_zero_using_original_indices();
	//then we order time vectors ascendingly
	void get_order_time_vectors_ascendingly_epochpartTime_above_zero();
	void get_order_time_vectors_ascendingly_tickpartTime_above_zero();
	//---------------------------------------------------------------------------------------

	//getting range of 1st element"not equalling zero" in unique not having 0
	void get_range_of_first_element_not_zero_in_unique_without_zero();
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds_without_zero;
	//first we make vector of time differences for range without zero using original indices
	void get_time_differences_range_of_first_element_without_zero_using_original_indices();
	//then we order time vectors ascendingly
	void get_order_time_vectors_ascendingly_epochpartTime_without_zero();
	void get_order_time_vectors_ascendingly_tickpartTime_without_zero();
	//---------------------------------------------------------------------------------------

	//getting range of last element in unique 
	void get_range_of_last_element_in_unique();
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds_last;
	//first we make vector of time differences for range last element using original indices
	void get_time_differences_range_of_last_element_using_original_indices();
	//then we order time vectors ascendingly
	void get_order_time_vectors_ascendingly_epochpartTime_last_element();
	void get_order_time_vectors_ascendingly_tickpartTime_last_element();

public:
	template <typename T>
	std::vector<size_t> ordered(std::vector<T> const& values) 
	{
		std::vector<size_t> indices(values.size());
		std::iota(begin(indices), end(indices), static_cast<size_t>(0));

		std::sort(
			begin(indices), end(indices),
			[&](size_t a, size_t b) { return values[a] < values[b]; }
		);
		return indices;
	}
	template <typename T>
	void ordered_by_old_indices(std::vector<T> const& values, std::vector<size_t>& indices)
	{
		std::vector<size_t> indices_1(indices.size());
		std::iota(begin(indices_1), end(indices_1), static_cast<size_t>(0));
		std::sort(
			begin(indices_1), end(indices_1),
			[&](size_t a, size_t b) { return values[a] < values[b]; }
		);
		assert(values.size() == indices_1.size());
		//assert([&]() { for (size_t i : indices_1) { if (i >= values.size()) return false; } return true; }());

		//std::sort(
		//	begin(indices), end(indices),
		//	[&](size_t a, size_t b) { return indices_1[a] < indices_1[b]; }
		//);
		//now I should use sorted indices_1 to pushback original indices into indices
		for (std::vector<size_t>::iterator indices_1_it = indices_1.begin(); indices_1_it != indices_1.end(); indices_1_it++)
		{
			indices.push_back(values[indices_1[indices_1_it - indices_1.begin()]]);
		}
		//return indices;
	}

	template <typename T> int sgn(T val) 
	{
		return (T(0) < val) - (val < T(0));
	}
};
#endif //CSV_MIN_TIME_WITH_PRICE_DIFFERENCE