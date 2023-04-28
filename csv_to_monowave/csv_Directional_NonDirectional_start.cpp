#include "csv_Directional_NonDirectional.h"
using namespace boost::chrono;

template<class D_ND_subclass>
void csv_Directional_NonDirectional::start_D_ND_identifier(int identifier)
{
	D_ND_degree_vec[current_degree].
		D_ND_subclass::identifier_m = identifier;
	//here we record its number of tick lines
	D_ND_degree_vec[current_degree].
		D_ND_subclass::number_moves_m = identifier;
	D_ND_degree_vec[current_degree].
		D_ND_subclass::identifier[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].D_ND_subclass::identifier_m);
	D_ND_degree_vec[current_degree].
		D_ND_subclass::number_moves[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].D_ND_subclass::number_moves_m);
}
template<class D_ND_subclass>
void csv_Directional_NonDirectional::start_D_ND_record_point_start()
{
	D_ND_degree_vec[current_degree].
		D_ND_subclass::start[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].D_ND_subclass::identifier_m);
}
//here we record total time of ND_up_main movement
template<class D_ND_subclass>
void csv_Directional_NonDirectional::start_D_ND_record_total_time_movement()
{
	D_ND_degree_vec[current_degree].
		D_ND_subclass::segment_time[Directional_NonDirectional_index] =
		tickpartTime_difference[Directional_NonDirectional_index] + D_ND_degree_vec[current_degree].
		D_ND_subclass::segment_time[Directional_NonDirectional_index - 1];
}

//here we record top price point in current movement
template<class D_ND_subclass>
void csv_Directional_NonDirectional::start_D_ND_record_top_price_current_movement()
{
	D_ND_degree_vec[current_degree].
		D_ND_subclass::top[Directional_NonDirectional_index] = std::max(bidPrice[Directional_NonDirectional_index], bidPrice[Directional_NonDirectional_index - 1]);
}
//here we record bottom price point in current movement
template<class D_ND_subclass>
void csv_Directional_NonDirectional::start_D_ND_record_bottom_price_current_movement()
{
	D_ND_degree_vec[current_degree].
		D_ND_subclass::bottom[Directional_NonDirectional_index] = std::min(bidPrice[Directional_NonDirectional_index], bidPrice[Directional_NonDirectional_index - 1]);
}
//here we record the new_price_action_top 
template<class D_ND_subclass>
void csv_Directional_NonDirectional::start_D_ND_record_new_price_action_top()
{
	//if current price >previous top
	if (bidPrice[Directional_NonDirectional_index] > 
		D_ND_degree_vec[current_degree].
		D_ND_subclass::top[Directional_NonDirectional_index - 1])
	{
		D_ND_degree_vec[current_degree].
			D_ND_subclass::new_price_action_top[Directional_NonDirectional_index] =
			(bidPrice[Directional_NonDirectional_index] -
				D_ND_degree_vec[current_degree].
				D_ND_subclass::top[Directional_NonDirectional_index - 1]);
	}
}
//here we record the new_price_action_bottom
template<class D_ND_subclass>
void csv_Directional_NonDirectional::start_D_ND_record_new_price_action_bottom()
{
	//if current price <previous bottom  note that value is negative
	if (bidPrice[Directional_NonDirectional_index] <
		D_ND_degree_vec[current_degree].
		D_ND_subclass::bottom[Directional_NonDirectional_index - 1])
	{
		D_ND_degree_vec[current_degree].
			D_ND_subclass::new_price_action_bottom[Directional_NonDirectional_index] =
			(bidPrice[Directional_NonDirectional_index] -
				D_ND_degree_vec[current_degree].
				D_ND_subclass::bottom[Directional_NonDirectional_index - 1]);
	}	
}
//here we record span between top and bottom points of ND_up_main
template<class D_ND_subclass>
void csv_Directional_NonDirectional::start_D_ND_record_span_top_bottom()
{
	D_ND_degree_vec[current_degree].
		D_ND_subclass::span[Directional_NonDirectional_index] =
		D_ND_degree_vec[current_degree].
		D_ND_subclass::top[Directional_NonDirectional_index]
		-
		D_ND_degree_vec[current_degree].
		D_ND_subclass::bottom[Directional_NonDirectional_index];

}