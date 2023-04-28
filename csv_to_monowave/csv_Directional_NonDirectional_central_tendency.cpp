#include "csv_Directional_NonDirectional.h"
#include <algorithm>    // std::sort

using namespace boost::chrono;
//here we make methods to calculate measures of central tendency "MEAN MEDIAN MODE"
//calculate mean of each subsegmet of movement
template<class D_ND_subclass>
void csv_Directional_NonDirectional::calculate_mean_each_subsegmet_movement()
{
	//1 get original indices of subsegment vector ordered ascendingly
	std::vector<size_t> Price_difference_movement_subsegment_original_indices = ordered(
		D_ND_degree_vec[current_degree].
		D_ND_subclass::sub_segment[Directional_NonDirectional_index]);
	//2 sort subsegment itself ascendingly
	std::vector<size_t> Price_difference_movement_subsegment_sorted = std::sort(
		D_ND_degree_vec[current_degree].
		D_ND_subclass::sub_segment.begin(), 
		D_ND_degree_vec[current_degree].
		D_ND_subclass::sub_segment.end());
	//3 get unique values of subsegments
	std::vector<size_t> Price_difference_movement_subsegment_unique = Price_difference_movement_subsegment_sorted;
	std::vector<int>::iterator it;
	it = std::unique(
		Price_difference_movement_subsegment_unique.begin(),
		Price_difference_movement_subsegment_unique.end());
	Price_difference_movement_subsegment_unique.resize(std::distance(Price_difference_movement_subsegment_unique.begin(), it));
	//4 calculate central tendency of price differences of unique values of subsegments
	 
	//4 getting range of each element in unique 
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds;
	int bounds_first_CURRENT_index = 0;
	int bounds_second_CURRENT_index = 0;
	for (int x = Price_difference_movement_subsegment_unique.begin(),
		x != Price_difference_movement_subsegment_unique.end(),x++)
	{
		bounds = std::equal_range(Price_difference_movement_subsegment_sorted.begin(), Price_difference_movement_subsegment_sorted.end(), Price_difference_movement_subsegment_unique[x]);
		//get the CURRENT index of bounds.first
		bounds_first_CURRENT_index = std::distance(Price_difference_movement_subsegment_sorted.begin(), bounds.first())
		//get the CURRENT index of bounds.second
		bounds_second_CURRENT_index = std::distance(Price_difference_movement_subsegment_sorted.begin(), bounds.first())
		//loop in Price_difference_movement_subsegment_original_indices to get original index of each value in Price_difference_movement_subsegment_sorted
		int original_index = 0;
		for (int y = bounds_first_CURRENT_index,y != bounds_second_CURRENT_index, y++)
		{
			original_index = Price_difference_movement_subsegment_original_indices[y];
			//third calculate mean of price differences
				//????????????????now
			////////int mean=bidPrice_difference[original_index]//////////
			//store mean in subsegment mean
			D_ND_degree_vec[current_degree].
				D_ND_subclass::sub_segment_mean[y] = (D_ND_degree_vec[current_degree].D_ND_subclass::identifier_m);
		}
		
	}
	
	
}
//calculate mean of all subsegmets of movement
	//calculate median of each subsegmet of movement
	//calculate median of all subsegmets of movement
	//calculate mode of each subsegmet of movement
	//calculate mode of all subsegmets of movement