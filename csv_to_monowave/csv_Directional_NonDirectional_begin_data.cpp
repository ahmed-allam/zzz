#include "csv_Directional_NonDirectional.h"
using namespace boost::chrono;

void csv_Directional_NonDirectional::start_begin_data()
{
	//we came here through if (Directional_NonDirectional_index == 1)
	//first if treats condition when data begins by zero move
	if (sgn(*it) == 0)
	{
		//we make first tickline zero move as move_start 1 
		D_ND_degree_vec[current_degree].
			bidPrice_difference_move_start_MS[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].move_start_MS);
		//we increment move_start_MS variable to be ready for next tickline
		D_ND_degree_vec[current_degree].move_start_MS++;

		D_ND_degree_vec[current_degree].
			bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].move_start_MS_number_of_moves);

		//we give this first tick line symbolic percentage value of POSITIVE_MAX because it has no previous price difference and also we use 0 as percentage if zero move comes after non zero move
		D_ND_degree_vec[current_degree].
			bidPrice_difference_to_previous_movement_percentage_many_percentages_var = std::numeric_limits<float>::max();
		bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = D_ND_degree_vec[current_degree].bidPrice_difference_to_previous_movement_percentage_many_percentages_var;

		//now we have 2 choices:
		//1st we can consider zero moves at beginning of data as useless and we start Directional and NonDirectional analysis at 1st nonzero move
		//2nd we can consider zero moves as NonDirectional up main and down main 
		start_begin_data_Zero_Move_as_NonDirectional();
		//in both cases we will do the following
		//1. we record the value in undetermined vector as positive_max"here positivity does not mean any thing ,we could have used negative_max or any extra large pos or neg number as marker
		D_ND_degree_vec[current_degree].
			bidPrice_difference_undetermined_price_difference_move[Directional_NonDirectional_index] = std::numeric_limits<float>::max();
		//2. we calulate the time duration of zero move so that we can use it to put this zero move in degree if we used 2nd case
		 
		//3. 
		start_begin_data_Directional();
	}
	else if (sgn(*it) != 0)
	{

	}
}
void csv_Directional_NonDirectional::start_begin_data_Zero_Move_as_NonDirectional()
{
	//we came here through if (Directional_NonDirectional_index == 1)then if (sgn(*it) == 0)
	//here we consider first tickline zero move as NonDirectional main >>>we will consider zero sideway is up sideway>>>this is modified to consider it as both up and down main ND then afterwards we will give it the direction of following directional move	

	//NonDirectional_ND_up_main
	//here we record the beginning of new ND_up_main and give it the number 1"first ND_up_main NonDirectional move"
	start_D_ND_identifier<NonDirectional_ND_up_main>(1);

	///////////we will to fill in subsegment after counter move is made>>>>after counter move is made then 1st subsegment started from start till counter move//////////////
	// 
	//here we record the point of start on ND_up_main using the number we gave to it as its identifier
	start_D_ND_record_point_start<NonDirectional_ND_up_main>();

	//at begin of data "1st tick line" we do not consider continuation,end or confirmation 	

	//here we record total time of ND_up_main movement
	start_D_ND_record_total_time_movement<NonDirectional_ND_up_main>();

	//here we record top price point in ND_up_main current movement
	start_D_ND_record_top_price_current_movement<NonDirectional_ND_up_main>();

	//here we record bottom price point in ND_up_main current movement
	start_D_ND_record_bottom_price_current_movement<NonDirectional_ND_up_main>();

	//here we record the new_price_action_top 
	start_D_ND_record_new_price_action_top<NonDirectional_ND_up_main>();
	//here we record the new_price_action_bottom 
	start_D_ND_record_new_price_action_bottom<NonDirectional_ND_up_main>();

	//here we record span between top and bottom points of ND_up_main
	start_D_ND_record_span_top_bottom<NonDirectional_ND_up_main>();

	

	//NonDirectional_ND_down_main
	//here we record the beginning of new ND_down_main and give it the number 1"first ND_down_main NonDirectional move"
	start_D_ND_identifier<NonDirectional_ND_down_main>(1);

	//here we record the point of start on ND_down_main using the number we gave to it as its identifier
	start_D_ND_record_point_start<NonDirectional_ND_down_main>();

	//at begin of data "1st tick line" we do not consider continuation,end or confirmation 
	//here we record total time of ND_up_main movement
	start_D_ND_record_total_time_movement<NonDirectional_ND_down_main>();

	//here we record top price point in ND_up_main current movement
	start_D_ND_record_top_price_current_movement<NonDirectional_ND_down_main>();

	//here we record bottom price point in ND_up_main current movement
	start_D_ND_record_bottom_price_current_movement<NonDirectional_ND_down_main>();

	//here we record the new_price_action_top 
	start_D_ND_record_new_price_action_top<NonDirectional_ND_down_main>();
	//here we record the new_price_action_bottom 
	start_D_ND_record_new_price_action_bottom<NonDirectional_ND_down_main>();

	//here we record span between top and bottom points of ND_up_main
	start_D_ND_record_span_top_bottom<NonDirectional_ND_down_main>();	


	//11-5-2021 we didnot yet make modifications on zero side way degree according to its time consumption?????????????????
}
void csv_Directional_NonDirectional::start_begin_data_Directional()
{
	start_begin_data_Directional_Up();
	start_begin_data_Directional_Down();
}

void csv_Directional_NonDirectional::start_begin_data_NonDirectional()
{

}

void csv_Directional_NonDirectional::start_begin_data_Directional_Up()
{

}
void csv_Directional_NonDirectional::start_begin_data_Directional_Down()
{

}
