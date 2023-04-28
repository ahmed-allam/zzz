#include "csv_min_time_with_price_difference.h"
#include "../Worker.h"

using namespace boost::chrono ;
void csv_min_time_with_price_difference::get_bidPrice_difference_absolute_original_indices()
{
	//I will make vector containing indices sorted ascendingly
	start = high_resolution_clock::now();
	bidPrice_difference_absolute_original_indices = ordered(bidPrice_difference_absolute);
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_sort_price_differences()
{
	start = high_resolution_clock::now();
	bidPrice_difference_absolute_sorted.resize(bidPrice_difference_absolute.size());
	std::partial_sort_copy(begin(bidPrice_difference_absolute),
		end(bidPrice_difference_absolute),
		begin(bidPrice_difference_absolute_sorted),
		end(bidPrice_difference_absolute_sorted));
	
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_unique_values_price_difference_absolute()
{
	start = high_resolution_clock::now();
	//get unique values of price difference absolute
	bidPrice_difference_absolute_sorted_unique = bidPrice_difference_absolute_sorted;
	it = std::unique(bidPrice_difference_absolute_sorted_unique.begin(), bidPrice_difference_absolute_sorted_unique.end());
	bidPrice_difference_absolute_sorted_unique.resize(std::distance(bidPrice_difference_absolute_sorted_unique.begin(), it));
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}

void csv_min_time_with_price_difference::get_range_of_first_element_in_unique_equalling_zero()
{
	start = high_resolution_clock::now();
	//getting range of 1st element in unique if it = zero
	//std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds_zero;
	bounds_zero = std::equal_range(bidPrice_difference_absolute_sorted.begin(), bidPrice_difference_absolute_sorted.end(), bidPrice_difference_absolute_sorted_unique[0]);

	//we can use bounds_zero to make vector of equal_range elements
	bidPrice_difference_absolute_min_zero = *(bounds_zero.first);
	std::cout << "bounds at positions " << (bounds_zero.first - bidPrice_difference_absolute_sorted.begin());
	std::cout << " and " << (bounds_zero.second - bidPrice_difference_absolute_sorted.begin()) << '\n';

	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_time_differences_range_of_zero_using_original_indices()
{
	start = high_resolution_clock::now();
	//first we make vector of time differences for range of zero using original indices
	for (std::vector<int>::iterator bidPrice_difference_absolute_sorted_it = bounds_zero.first; bidPrice_difference_absolute_sorted_it != bounds_zero.second; bidPrice_difference_absolute_sorted_it++)
	{
		//we get original epochpartTime_difference for each bidPrice_difference_absolute_sorted
		//the order of epochpartTime_difference is relative to bidPrice_difference_absolute_sorted
		bidPrice_difference_absolute_sorted_epochpartTime_difference_zero.push_back(epochpartTime_difference[bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]]);

		bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_original_indices.push_back(bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]);

		//we get original tickpartTime_difference for each bidPrice_difference_absolute_sorted
		//the order of tickpartTime_difference is relative to bidPrice_difference_absolute_sorted
		bidPrice_difference_absolute_sorted_tickpartTime_difference_zero.push_back(tickpartTime_difference[bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]]);
		bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_original_indices.push_back(bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]);
	}
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_order_time_vectors_ascendingly_epochpartTime_zero()
{
	start = high_resolution_clock::now();
	//then we order time vectors ascendingly now the epochpartTime differences
	//first we order local index of epochpartTime difference for zero range ascendingly in new vector
	bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_local_indices_sorted = ordered(bidPrice_difference_absolute_sorted_epochpartTime_difference_zero);
	//second we resort original indices according to epochpartTime differences for zero range local index
	for (std::vector<size_t>::iterator indices_local_it = bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_local_indices_sorted.begin(); indices_local_it != bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_local_indices_sorted.end(); indices_local_it++)
	{
		int bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_local_indices_sorted_element_value = *indices_local_it;
		bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_original_indices_resorted.push_back(bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_original_indices[bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_local_indices_sorted_element_value]);
	}
	//third we sort epochpartTime differences ascendingly in new vector"bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted"
	bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted.resize(bidPrice_difference_absolute_sorted_epochpartTime_difference_zero.size());
	std::partial_sort_copy(begin(bidPrice_difference_absolute_sorted_epochpartTime_difference_zero),
		end(bidPrice_difference_absolute_sorted_epochpartTime_difference_zero),
		begin(bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted),
		end(bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted));
	//the following may be not needed
	
	//get unique values of bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted which is epochpartTime difference"not bid price difference"
	bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted_unique = bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted;
	it = std::unique(bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted_unique.begin(), bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted_unique.end());
	bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted_unique.resize(std::distance(bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted_unique.begin(), it));
	
	/*
	print out content:
	std::cout << "bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted_unique contains:";
	for (it = bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted_unique.begin(); it != bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted_unique.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted contains:";
	for (it = bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted.begin(); it != bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted.end(); ++it)
		std::cout << ' ' << *it << ' ' << bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_original_indices_resorted[it- bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted.begin()]<< ' ' << epochpartTime_difference[bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_original_indices_resorted[it - bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted.begin()]];
	std::cout << '\n';
	*/
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_order_time_vectors_ascendingly_tickpartTime_zero()
{
	start = high_resolution_clock::now();
	//then we order time vectors ascendingly now the tickpartTime differences
	//first we order local index of tickpartTime difference for zero range ascendingly in new vector
	bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_local_indices_sorted = ordered(bidPrice_difference_absolute_sorted_tickpartTime_difference_zero);
	//second we resort original indices according to tickpartTime differences for zero range local index
	for (std::vector<size_t>::iterator indices_local_it = bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_local_indices_sorted.begin(); indices_local_it != bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_local_indices_sorted.end(); indices_local_it++)
	{
		int bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_local_indices_sorted_element_value = *indices_local_it;
		bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_original_indices_resorted.push_back(bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_original_indices[bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_local_indices_sorted_element_value]);
	}
	//third we sort tickpartTime differences ascendingly in new vector"bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted"

	bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted.resize(bidPrice_difference_absolute_sorted_tickpartTime_difference_zero.size());
	std::partial_sort_copy(begin(bidPrice_difference_absolute_sorted_tickpartTime_difference_zero),
		end(bidPrice_difference_absolute_sorted_tickpartTime_difference_zero),
		begin(bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted),
		end(bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted));

	//get unique values of bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted which is tickpartTime difference"not bid price difference"
	bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted_unique = bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted;
	it = std::unique(bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted_unique.begin(), bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted_unique.end());
	bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted_unique.resize(std::distance(bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted_unique.begin(), it));
	/*
	// print out content:
	std::cout << "bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted_unique contains:";
	for (it = bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted_unique.begin(); it != bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted_unique.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted contains:";
	for (it = bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted.begin(); it != bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted.end(); ++it)
		std::cout << ' ' << *it << ' ' << bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_original_indices_resorted[it - bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted.begin()] << ' ' << tickpartTime_difference[bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_original_indices_resorted[it - bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted.begin()]];
	std::cout << '\n';
	*/
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}

void csv_min_time_with_price_difference::get_range_of_first_element_above_zero_in_unique_having_zero()
{
	start = high_resolution_clock::now();
	//getting range of 1st element"not equalling zero" in unique having 0
	bounds_with_zero = std::equal_range(bidPrice_difference_absolute_sorted.begin(), bidPrice_difference_absolute_sorted.end(), bidPrice_difference_absolute_sorted_unique[1]);
	
	//we can use bounds_with_zero to make vector of equal_range elements
	bidPrice_difference_absolute_min_above_zero = *(bounds_with_zero.first);
	std::cout << "bounds at positions " << (bounds_with_zero.first - bidPrice_difference_absolute_sorted.begin());
	std::cout << " and " << (bounds_with_zero.second - bidPrice_difference_absolute_sorted.begin()) << '\n';

	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_time_differences_range_of_first_element_above_zero_using_original_indices()
{
	start = high_resolution_clock::now();
	//first we make vector of time differences for range of above zero using original indices
	for (std::vector<int>::iterator bidPrice_difference_absolute_sorted_it = bounds_with_zero.first; bidPrice_difference_absolute_sorted_it != bounds_with_zero.second; bidPrice_difference_absolute_sorted_it++)
	{
		//we get original epochpartTime_difference for each bidPrice_difference_absolute_sorted
		//the order of epochpartTime_difference is relative to bidPrice_difference_absolute_sorted
		bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero.push_back(epochpartTime_difference[bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]]);

		bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_original_indices.push_back(bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]);

		//we get original tickpartTime_difference for each bidPrice_difference_absolute_sorted
		//the order of tickpartTime_difference is relative to bidPrice_difference_absolute_sorted
		bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero.push_back(tickpartTime_difference[bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]]);
		bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_original_indices.push_back(bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]);
	}
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_order_time_vectors_ascendingly_epochpartTime_above_zero()
{
	start = high_resolution_clock::now();
	//then we order time vectors ascendingly now the epochpartTime differences
	//first we order local index of epochpartTime difference for above_zero range ascendingly in new vector
	bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_local_indices_sorted = ordered(bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero);
	//second we resort original indices according to epochpartTime differences for above_zero range local index
	for (std::vector<size_t>::iterator indices_local_it = bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_local_indices_sorted.begin(); indices_local_it != bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_local_indices_sorted.end(); indices_local_it++)
	{
		int bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_local_indices_sorted_element_value = *indices_local_it;
		bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_original_indices_resorted.push_back(bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_original_indices[bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_local_indices_sorted_element_value]);
	}
	//third we sort epochpartTime differences ascendingly in new vector"bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted"
	bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted.resize(bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero.size());
	std::partial_sort_copy(begin(bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero),
		end(bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero),
		begin(bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted),
		end(bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted));

	//get unique values of bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted which is epochpartTime difference"not bid price difference"
	bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted_unique = bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted;
	it = std::unique(bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted_unique.begin(), bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted_unique.end());
	bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted_unique.resize(std::distance(bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted_unique.begin(), it));
	/*
	// print out content:
	std::cout << "bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted_unique contains:";
	for (it = bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted_unique.begin(); it != bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted_unique.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted contains:";
	for (it = bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted.begin(); it != bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted.end(); ++it)
		std::cout << ' ' << *it << ' ' << bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_original_indices_resorted[it- bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted.begin()]<< ' ' << epochpartTime_difference[bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_original_indices_resorted[it - bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted.begin()]];
	std::cout << '\n';
	*/
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_order_time_vectors_ascendingly_tickpartTime_above_zero()
{
	start = high_resolution_clock::now();
	//first we order local index of tickpartTime difference for above_zero range ascendingly in new vector
	bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_local_indices_sorted = ordered(bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero);
	//second we resort original indices according to tickpartTime differences for above_zero range local index
	for (std::vector<size_t>::iterator indices_local_it = bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_local_indices_sorted.begin(); indices_local_it != bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_local_indices_sorted.end(); indices_local_it++)
	{
		int bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_local_indices_sorted_element_value = *indices_local_it;
		bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_original_indices_resorted.push_back(bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_original_indices[bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_local_indices_sorted_element_value]);
	}
	//third we sort tickpartTime differences ascendingly in new vector"bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted"
	bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted.resize(bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero.size());
	std::partial_sort_copy(begin(bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero),
		end(bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero),
		begin(bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted),
		end(bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted));

	//get unique values of bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted which is tickpartTime difference"not bid price difference"
	bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted_unique = bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted;
	it = std::unique(bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted_unique.begin(), bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted_unique.end());
	bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted_unique.resize(std::distance(bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted_unique.begin(), it));
	/*
	// print out content:
	std::cout << "bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted_unique contains:";
	for (it = bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted_unique.begin(); it != bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted_unique.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted contains:";
	for (it = bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted.begin(); it != bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted.end(); ++it)
		std::cout << ' ' << *it << ' ' << bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_original_indices_resorted[it - bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted.begin()] << ' ' << tickpartTime_difference[bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_original_indices_resorted[it - bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted.begin()]];
	std::cout << '\n';
	*/
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}

void csv_min_time_with_price_difference::get_range_of_first_element_not_zero_in_unique_without_zero()
{
	start = high_resolution_clock::now();
	//getting range of 1st element"not equalling zero" in unique not having 0
	bounds_without_zero = std::equal_range(bidPrice_difference_absolute_sorted.begin(), bidPrice_difference_absolute_sorted.end(), bidPrice_difference_absolute_sorted_unique[0]);	

	//we can use bounds_without_zero to make vector of equal_range elements
	bidPrice_difference_absolute_min_without_zero = *(bounds_without_zero.first);
	std::cout << "bounds at positions " << (bounds_without_zero.first - bidPrice_difference_absolute_sorted.begin());
	std::cout << " and " << (bounds_without_zero.second - bidPrice_difference_absolute_sorted.begin()) << '\n';

	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_time_differences_range_of_first_element_without_zero_using_original_indices()
{
	start = high_resolution_clock::now();
	//first we make vector of time differences for range of without_zero using original indices
	for (std::vector<int>::iterator bidPrice_difference_absolute_sorted_it = bounds_without_zero.first; bidPrice_difference_absolute_sorted_it != bounds_without_zero.second; bidPrice_difference_absolute_sorted_it++)
	{
		//we get original epochpartTime_difference for each bidPrice_difference_absolute_sorted
		//the order of epochpartTime_difference is relative to bidPrice_difference_absolute_sorted
		bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero.push_back(epochpartTime_difference[bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]]);

		bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_original_indices.push_back(bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]);

		//we get original tickpartTime_difference for each bidPrice_difference_absolute_sorted
		//the order of tickpartTime_difference is relative to bidPrice_difference_absolute_sorted
		bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero.push_back(tickpartTime_difference[bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]]);
		bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_original_indices.push_back(bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]);
	}
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_order_time_vectors_ascendingly_epochpartTime_without_zero()
{
	start = high_resolution_clock::now();
	//first we order local index of epochpartTime difference for without_zero range ascendingly in new vector
	bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_local_indices_sorted = ordered(bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero);
	//second we resort original indices according to epochpartTime differences for without_zero range local index
	for (std::vector<size_t>::iterator indices_local_it = bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_local_indices_sorted.begin(); indices_local_it != bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_local_indices_sorted.end(); indices_local_it++)
	{
		int bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_local_indices_sorted_element_value = *indices_local_it;
		bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_original_indices_resorted.push_back(bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_original_indices[bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_local_indices_sorted_element_value]);
	}
	//third we sort epochpartTime differences ascendingly in new vector"bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted"
	bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted.resize(bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero.size());
	std::partial_sort_copy(begin(bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero),
		end(bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero),
		begin(bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted),
		end(bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted));

	//get unique values of bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted which is epochpartTime difference"not bid price difference"
	bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted_unique = bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted;
	it = std::unique(bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted_unique.begin(), bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted_unique.end());
	bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted_unique.resize(std::distance(bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted_unique.begin(), it));
	/*
	// print out content:
	std::cout << "bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted_unique contains:";
	for (it = bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted_unique.begin(); it != bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted_unique.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted contains:";
	for (it = bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted.begin(); it != bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted.end(); ++it)
		std::cout << ' ' << *it << ' ' << bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_original_indices_resorted[it- bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted.begin()]<< ' ' << epochpartTime_difference[bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_original_indices_resorted[it - bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted.begin()]];
	std::cout << '\n';
	*/
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_order_time_vectors_ascendingly_tickpartTime_without_zero()
{
	start = high_resolution_clock::now();
	//first we order local index of tickpartTime difference for without_zero range ascendingly in new vector
	bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_local_indices_sorted = ordered(bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero);
	//second we resort original indices according to tickpartTime differences for without_zero range local index
	for (std::vector<size_t>::iterator indices_local_it = bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_local_indices_sorted.begin(); indices_local_it != bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_local_indices_sorted.end(); indices_local_it++)
	{
		int bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_local_indices_sorted_element_value = *indices_local_it;
		bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_original_indices_resorted.push_back(bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_original_indices[bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_local_indices_sorted_element_value]);
	}
	//third we sort tickpartTime differences ascendingly in new vector"bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted"
	bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted.resize(bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero.size());
	std::partial_sort_copy(begin(bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero),
		end(bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero),
		begin(bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted),
		end(bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted));

	//get unique values of bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted which is tickpartTime difference"not bid price difference"
	bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted_unique = bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted;
	it = std::unique(bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted_unique.begin(), bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted_unique.end());
	bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted_unique.resize(std::distance(bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted_unique.begin(), it));
	/*
	// print out content:
	std::cout << "bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted_unique contains:";
	for (it = bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted_unique.begin(); it != bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted_unique.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted contains:";
	for (it = bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted.begin(); it != bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted.end(); ++it)
		std::cout << ' ' << *it << ' ' << bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_original_indices_resorted[it - bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted.begin()] << ' ' << tickpartTime_difference[bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_original_indices_resorted[it - bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted.begin()]];
	std::cout << '\n';
	*/
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}

void csv_min_time_with_price_difference::get_range_of_last_element_in_unique()
{
	start = high_resolution_clock::now();
	//getting range of last element in unique
	bounds_last = std::equal_range(bidPrice_difference_absolute_sorted.begin(), bidPrice_difference_absolute_sorted.end(), bidPrice_difference_absolute_sorted_unique.back());
	
	//we can use bounds_last to make vector of equal_range elements
	bidPrice_difference_absolute_max = *(bounds_last.first);
	std::cout << "bounds at positions " << (bounds_last.first - bidPrice_difference_absolute_sorted.begin());
	std::cout << " and " << (bounds_last.second - bidPrice_difference_absolute_sorted.begin()) << '\n';

	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_time_differences_range_of_last_element_using_original_indices()
{
	start = high_resolution_clock::now();
	//first we make vector of time differences for range of max using original indices
	for (std::vector<int>::iterator bidPrice_difference_absolute_sorted_it = bounds_last.first; bidPrice_difference_absolute_sorted_it != bounds_last.second; bidPrice_difference_absolute_sorted_it++)
	{
		//we get original epochpartTime_difference for each bidPrice_difference_absolute_sorted
		//the order of epochpartTime_difference is relative to bidPrice_difference_absolute_sorted
		bidPrice_difference_absolute_sorted_epochpartTime_difference_last.push_back(epochpartTime_difference[bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]]);

		bidPrice_difference_absolute_sorted_epochpartTime_difference_last_original_indices.push_back(bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]);

		//we get original tickpartTime_difference for each bidPrice_difference_absolute_sorted
		//the order of tickpartTime_difference is relative to bidPrice_difference_absolute_sorted
		bidPrice_difference_absolute_sorted_tickpartTime_difference_last.push_back(tickpartTime_difference[bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]]);
		bidPrice_difference_absolute_sorted_tickpartTime_difference_last_original_indices.push_back(bidPrice_difference_absolute_original_indices[bidPrice_difference_absolute_sorted_it - bidPrice_difference_absolute_sorted.begin()]);
	}
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_order_time_vectors_ascendingly_epochpartTime_last_element()
{
	start = high_resolution_clock::now();

	//first we order local index of epochpartTime difference for last range ascendingly in new vector
	bidPrice_difference_absolute_sorted_epochpartTime_difference_last_local_indices_sorted = ordered(bidPrice_difference_absolute_sorted_epochpartTime_difference_last);
	//second we resort original indices according to epochpartTime differences for last range local index
	for (std::vector<size_t>::iterator indices_local_it = bidPrice_difference_absolute_sorted_epochpartTime_difference_last_local_indices_sorted.begin(); indices_local_it != bidPrice_difference_absolute_sorted_epochpartTime_difference_last_local_indices_sorted.end(); indices_local_it++)
	{
		int bidPrice_difference_absolute_sorted_epochpartTime_difference_last_local_indices_sorted_element_value = *indices_local_it;
		bidPrice_difference_absolute_sorted_epochpartTime_difference_last_original_indices_resorted.push_back(bidPrice_difference_absolute_sorted_epochpartTime_difference_last_original_indices[bidPrice_difference_absolute_sorted_epochpartTime_difference_last_local_indices_sorted_element_value]);
	}
	//third we sort epochpartTime differences ascendingly in new vector"bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted"

	bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted.resize(bidPrice_difference_absolute_sorted_epochpartTime_difference_last.size());
	std::partial_sort_copy(begin(bidPrice_difference_absolute_sorted_epochpartTime_difference_last),
		end(bidPrice_difference_absolute_sorted_epochpartTime_difference_last),
		begin(bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted),
		end(bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted));

	//get unique values of bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted which is epochpartTime difference"not bid price difference"
	bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted_unique = bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted;
	it = std::unique(bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted_unique.begin(), bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted_unique.end());
	bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted_unique.resize(std::distance(bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted_unique.begin(), it));
	/*
	// print out content:
	std::cout << "bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted_unique contains:";
	for (it = bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted_unique.begin(); it != bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted_unique.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted contains:";
	for (it = bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted.begin(); it != bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted.end(); ++it)
		std::cout << ' ' << *it << ' ' << bidPrice_difference_absolute_sorted_epochpartTime_difference_last_original_indices_resorted[it- bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted.begin()]<< ' ' << epochpartTime_difference[bidPrice_difference_absolute_sorted_epochpartTime_difference_last_original_indices_resorted[it - bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted.begin()]];
	std::cout << '\n';
	*/
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_min_time_with_price_difference::get_order_time_vectors_ascendingly_tickpartTime_last_element()
{
	start = high_resolution_clock::now();
	//first we order local index of tickpartTime difference for last range ascendingly in new vector
	bidPrice_difference_absolute_sorted_tickpartTime_difference_last_local_indices_sorted = ordered(bidPrice_difference_absolute_sorted_tickpartTime_difference_last);
	//second we resort original indices according to tickpartTime differences for last range local index
	for (std::vector<size_t>::iterator indices_local_it = bidPrice_difference_absolute_sorted_tickpartTime_difference_last_local_indices_sorted.begin(); indices_local_it != bidPrice_difference_absolute_sorted_tickpartTime_difference_last_local_indices_sorted.end(); indices_local_it++)
	{
		int bidPrice_difference_absolute_sorted_tickpartTime_difference_last_local_indices_sorted_element_value = *indices_local_it;
		bidPrice_difference_absolute_sorted_tickpartTime_difference_last_original_indices_resorted.push_back(bidPrice_difference_absolute_sorted_tickpartTime_difference_last_original_indices[bidPrice_difference_absolute_sorted_tickpartTime_difference_last_local_indices_sorted_element_value]);
	}
	//third we sort tickpartTime differences ascendingly in new vector"bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted"

	bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted.resize(bidPrice_difference_absolute_sorted_tickpartTime_difference_last.size());
	std::partial_sort_copy(begin(bidPrice_difference_absolute_sorted_tickpartTime_difference_last),
		end(bidPrice_difference_absolute_sorted_tickpartTime_difference_last),
		begin(bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted),
		end(bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted));

	//get unique values of bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted which is tickpartTime difference"not bid price difference"
	bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted_unique = bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted;
	it = std::unique(bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted_unique.begin(), bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted_unique.end());
	bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted_unique.resize(std::distance(bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted_unique.begin(), it));
	/*
	// print out content:
	std::cout << "bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted_unique contains:";
	for (it = bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted_unique.begin(); it != bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted_unique.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted contains:";
	for (it = bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted.begin(); it != bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted.end(); ++it)
		std::cout << ' ' << *it << ' ' << bidPrice_difference_absolute_sorted_tickpartTime_difference_last_original_indices_resorted[it - bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted.begin()] << ' ' << tickpartTime_difference[bidPrice_difference_absolute_sorted_tickpartTime_difference_last_original_indices_resorted[it - bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted.begin()]];
	std::cout << '\n';
	*/
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
/*
{
	start = high_resolution_clock::now();

	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
*/
csv_min_time_with_price_difference::csv_min_time_with_price_difference()
	:csv_time_bid_ask_difference()
{
	
}

//__host__ 
csv_min_time_with_price_difference::csv_min_time_with_price_difference(Worker* workerPtr)
	:csv_time_bid_ask_difference(workerPtr)
{
	plot_flag = csv_min_time_with_price_difference_m;

	//I want to sort price differences,and keep original indices 
	get_bidPrice_difference_absolute_original_indices();
	get_sort_price_differences();
	//get unique values of price difference absolute
	get_unique_values_price_difference_absolute();
		
	if ((*bidPrice_difference_absolute_sorted.begin()) == 0)
	{	
		//getting range of 1st element in unique if it = zero in bidPrice_difference_absolute_sorted_it
		get_range_of_first_element_in_unique_equalling_zero();

		//then getting min and max time difference for zero price difference		
		//first we make vector of time differences for range of zero using original indices
		get_time_differences_range_of_zero_using_original_indices();
		//then we order time vectors ascendingly
		get_order_time_vectors_ascendingly_epochpartTime_zero();
		//now we get epochpartTime difference min and max for range of 0
		epochpartTime_difference_min_zero = bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted[1];//look at it in future [1]???>>>we use [1] because [0] is always =0 by our definition
		epochpartTime_difference_max_zero = bidPrice_difference_absolute_sorted_epochpartTime_difference_zero_sorted.back();
		std::cout <<"epochpartTime_difference_min_zero:" << epochpartTime_difference_min_zero<< " epochpartTime_difference_max_zero:"<< epochpartTime_difference_max_zero << '\n';

		get_order_time_vectors_ascendingly_tickpartTime_zero();		
		//now we get tickpartTime difference min and max for range of 0
		tickpartTime_difference_min_zero = bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted[1];
		tickpartTime_difference_max_zero = bidPrice_difference_absolute_sorted_tickpartTime_difference_zero_sorted.back();
		std::cout << "tickpartTime_difference_min_zero:" << tickpartTime_difference_min_zero << " tickpartTime_difference_max_zero:" << tickpartTime_difference_max_zero << '\n';		
		//----------------------------------------------------------------------------------------------------------------------------
		//getting range of 1st element"not equalling zero" in unique having 0
		get_range_of_first_element_above_zero_in_unique_having_zero();
		//then getting min and max time difference for above zero price difference
		//first we make vector of time differences for range of above zero using original indices
		get_time_differences_range_of_first_element_above_zero_using_original_indices();
		//then we order time vectors ascendingly
		get_order_time_vectors_ascendingly_epochpartTime_above_zero();		
		//now we get epochpartTime difference min and max for range of value above 0
		epochpartTime_difference_min_above_zero = bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted[0];
		epochpartTime_difference_max_above_zero = bidPrice_difference_absolute_sorted_epochpartTime_difference_above_zero_sorted.back();
		std::cout << "epochpartTime_difference_min_above_zero:" << epochpartTime_difference_min_above_zero << " epochpartTime_difference_max_above_zero:" << epochpartTime_difference_max_above_zero << '\n';

		get_order_time_vectors_ascendingly_tickpartTime_above_zero();
		
		//now we get tickpartTime difference min and max for range of value above 0
		tickpartTime_difference_min_above_zero = bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted[1];
		tickpartTime_difference_max_above_zero = bidPrice_difference_absolute_sorted_tickpartTime_difference_above_zero_sorted.back();
		std::cout << "tickpartTime_difference_min_above_zero:" << tickpartTime_difference_min_above_zero << " tickpartTime_difference_max_above_zero:" << tickpartTime_difference_max_above_zero << '\n';
	}
	else if ((*bidPrice_difference_absolute_sorted.begin()) != 0)//i will remove else i will make it == to test the code ???
	//if ((*bidPrice_difference_absolute_sorted.begin()) == 0)
	{
		//getting range of 1st element in unique not having 0
		get_range_of_first_element_not_zero_in_unique_without_zero();
		//then getting min and max time difference for without_zero price difference
		//first we make vector of time differences for range of without_zero using original indices
		get_time_differences_range_of_first_element_without_zero_using_original_indices();
		//then we order time vectors ascendingly
		get_order_time_vectors_ascendingly_epochpartTime_without_zero();
		//now we get epochpartTime difference min and max for range of without 0
		epochpartTime_difference_min_without_zero = bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted[0];
		epochpartTime_difference_max_without_zero = bidPrice_difference_absolute_sorted_epochpartTime_difference_without_zero_sorted.back();
		std::cout << "epochpartTime_difference_min_without_zero:" << epochpartTime_difference_min_without_zero << " epochpartTime_difference_max_without_zero:" << epochpartTime_difference_max_without_zero << '\n';

		get_order_time_vectors_ascendingly_tickpartTime_without_zero();
		//now we get tickpartTime difference min and max for range of 0
		tickpartTime_difference_min_without_zero = bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted[1];
		tickpartTime_difference_max_without_zero = bidPrice_difference_absolute_sorted_tickpartTime_difference_without_zero_sorted.back();
		std::cout << "tickpartTime_difference_min_without_zero:" << tickpartTime_difference_min_without_zero << " tickpartTime_difference_max_without_zero:" << tickpartTime_difference_max_without_zero << '\n';
	}
	
	//getting range of last element in unique
	get_range_of_last_element_in_unique();
	//then getting min and max time difference for max price difference
	//first we make vector of time differences for range of max using original indices
	get_time_differences_range_of_last_element_using_original_indices();
	//then we order time vectors ascendingly

	get_order_time_vectors_ascendingly_epochpartTime_last_element();
	//now we get epochpartTime difference min and max for range of last
	epochpartTime_difference_min_last = bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted[0];
	epochpartTime_difference_max_last = bidPrice_difference_absolute_sorted_epochpartTime_difference_last_sorted.back();
	std::cout << "epochpartTime_difference_min_last:" << epochpartTime_difference_min_last << " epochpartTime_difference_max_last:" << epochpartTime_difference_max_last << '\n';

	get_order_time_vectors_ascendingly_tickpartTime_last_element();
	//now we get tickpartTime difference min and max for range of last
	tickpartTime_difference_min_last = bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted[0];
	tickpartTime_difference_max_last = bidPrice_difference_absolute_sorted_tickpartTime_difference_last_sorted.back();
	std::cout << "tickpartTime_difference_min_last:" << tickpartTime_difference_min_last << " tickpartTime_difference_max_last:" << tickpartTime_difference_max_last << '\n';


	//now we get whole min and max time difference for price difference
	//first we make vector of time differences
	//note that min and max epochpartTime differences range from 0 to more than 49 hours in case of holidays So we need to make sure epochpartTime difference is not occuring in any of off times>>>>to be made in future after getting off times.So we now use tickpartTime difference only although this will not show time difference of tick taking more than one hour in normal working time
	epochpartTime_difference_sorted_original_indices = ordered(epochpartTime_difference);
	epochpartTime_difference_sorted.resize(epochpartTime_difference.size());
	std::partial_sort_copy(begin(epochpartTime_difference),
		end(epochpartTime_difference),
		begin(epochpartTime_difference_sorted),
		end(epochpartTime_difference_sorted));
	//get unique values of epochpartTime_difference
	epochpartTime_difference_sorted_unique = epochpartTime_difference_sorted;
	it = std::unique(epochpartTime_difference_sorted_unique.begin(), epochpartTime_difference_sorted_unique.end());
	epochpartTime_difference_sorted_unique.resize(std::distance(epochpartTime_difference_sorted_unique.begin(), it));

	epochpartTime_difference_min = epochpartTime_difference_sorted_unique[0];
	epochpartTime_difference_max = epochpartTime_difference_sorted_unique.back();

	tickpartTime_difference_sorted_original_indices = ordered(tickpartTime_difference);
	tickpartTime_difference_sorted.resize(tickpartTime_difference.size());
	std::partial_sort_copy(begin(tickpartTime_difference),
		end(tickpartTime_difference),
		begin(tickpartTime_difference_sorted),
		end(tickpartTime_difference_sorted));	
	//get unique values of tickpartTime_difference
	tickpartTime_difference_sorted_unique = tickpartTime_difference_sorted;
	it = std::unique(tickpartTime_difference_sorted_unique.begin(), tickpartTime_difference_sorted_unique.end());
	tickpartTime_difference_sorted_unique.resize(std::distance(tickpartTime_difference_sorted_unique.begin(), it));

	tickpartTime_difference_min= tickpartTime_difference_sorted_unique[1];
	tickpartTime_difference_max= tickpartTime_difference_sorted_unique.back();

	
	bidPrice_timeunit = tickpartTime_difference_min;
	bidPrice_priceunit = bidPrice_difference_absolute_min_above_zero;//25-12-2020??????????????????????????????????
	//25-12-2020
	//calculate number of time and price units for each tick to tick price difference
	for (std::vector<int>::iterator it = tickpartTime_difference.begin(); it != tickpartTime_difference.end(); ++it)
	{
		bidPrice_difference_tickpartTime_difference_time_units.push_back((*it)/ bidPrice_timeunit);
	}
	for (std::vector<int>::iterator it = bidPrice_difference.begin(); it != bidPrice_difference.end(); ++it)
	{
		bidPrice_difference_price_units.push_back((*it) / bidPrice_priceunit);
	}
	/*
	std::cout << "epochpartTime_difference_min:"
		<< ' '
		<< epochpartTime_difference_min 
		<< ' '
		<< "epochpartTime_difference_max:"
		<< ' '
		<< epochpartTime_difference_max 
		<< ' '
		<< "tickpartTime_difference_min:"
		<< ' '
		<< tickpartTime_difference_min 
		<< ' '
		<< "tickpartTime_difference_max:"
		<< ' '
		<< tickpartTime_difference_max
		<< ' '
		<< "at:"
		<< tickpartTime_difference_sorted_original_indices[tickpartTime_difference_sorted.end()- tickpartTime_difference_sorted.begin()-1]
		<< " "
		<< *(tickpartTime_difference_sorted_unique.end()-2)
		<< "at:"
		<< tickpartTime_difference_sorted_original_indices[tickpartTime_difference_sorted.end() - tickpartTime_difference_sorted.begin() - 2]
		<< " "
		<< std::endl;
	*/
	/*
	for (int n = 0; n < bidPrice_difference_absolute.size(); n++)
	{
		std::cout
			
			<< bidPrice_difference_absolute_sorted[n] << ' '			
			<< bidPrice_difference_absolute_original_indices[n] << ' '
			<< bidPrice_difference_absolute[bidPrice_difference_absolute_original_indices[n]] << ' '
			<< std::endl;
		//if (bidPrice_difference_absolute_sorted[n]>0)
		//{
		//	std::cout << "greater than zero" << std::endl;
		//}
	}
	*/
	/*
	auto maxElementIndex = std::max_element(bidPrice_difference_absolute.begin(),bidPrice_difference_absolute.end()) - bidPrice_difference_absolute.begin();
	long maxElement = *std::max_element(bidPrice_difference_absolute.begin(), bidPrice_difference_absolute.end());

	auto minElementIndex = std::min_element(bidPrice_difference.begin(),bidPrice_difference.end()) - bidPrice_difference.begin();
	auto minElement = *std::min_element(bidPrice_difference.begin(), bidPrice_difference.end());

	std::cout << "maxElementIndex:" << maxElementIndex << ", maxElement:" << maxElement << '\n';
	std::cout << "minElementIndex:" << minElementIndex << ", minElement:" << minElement << '\n';
	*/
	// After function call 
	auto stop = high_resolution_clock::now();
	// Subtract stop and start timepoints and 
	// cast it to required unit. Predefined units 
	// are nanoseconds, microseconds, milliseconds, 
	// seconds, minutes, hours. Use duration_cast() 
	// function. 
	auto duration = duration_cast<microseconds>(stop - start);   
	// To get the value of duration use the count() 
	// member function on the duration object 
	std::cout << duration.count() << std::endl; 
	/*
	start = high_resolution_clock::now();
	maxElementIndex = std::max_element(askPrice_difference.begin(),askPrice_difference.end()) - askPrice_difference.begin();
	maxElement = *std::max_element(askPrice_difference.begin(), askPrice_difference.end());

	minElementIndex = std::min_element(askPrice_difference.begin(),askPrice_difference.end()) - askPrice_difference.begin();
	minElement = *std::min_element(askPrice_difference.begin(), askPrice_difference.end());

	std::cout << "maxElementIndex:" << maxElementIndex << ", maxElement:" << maxElement << '\n';
	std::cout << "minElementIndex:" << minElementIndex << ", minElement:" << minElement << '\n';
	// After function call 
	stop = high_resolution_clock::now();
	// Subtract stop and start timepoints and 
	// cast it to required unit. Predefined units 
	// are nanoseconds, microseconds, milliseconds, 
	// seconds, minutes, hours. Use duration_cast() 
	// function. 
	duration = duration_cast<microseconds>(stop - start);   
	// To get the value of duration use the count() 
	// member function on the duration object 
	std::cout << duration.count() << std::endl;   
	*/
	//17-9-2021 we will plot bid ask prices differences,ticks time differences	
	emit workerPtr->updateTable(this);
	mutex.lock();
	updateTable_waiting.wait(&mutex);
	mutex.unlock();
	emit workerPtr->plotGraph(this);
	mutex.lock();
	plotGraph_waiting.wait(&mutex);
	mutex.unlock();
}
