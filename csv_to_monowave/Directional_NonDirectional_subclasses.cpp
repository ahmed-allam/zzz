#include "Directional_NonDirectional_subclasses.h"

Multi_Segment_Same_Direction::Multi_Segment_Same_Direction(csv_Directional_NonDirectional* current_monowave_class_ptr, int array_size)
{
	bidPrice_difference_move_start_MS_number_of_moves.resize(array_size);
	bidPrice_difference_move_start_MS.resize(array_size);
	bidPrice_difference_multi_segment_same_direction.resize(array_size);

	//prepare_vectors_begining_of_data 
	bidPrice_difference_move_start_MS_number_of_moves[0] = 0;
	bidPrice_difference_move_start_MS[0] = 0;
	bidPrice_difference_multi_segment_same_direction[0] = 0;
}

Directional_D_up_main::Directional_D_up_main(csv_Directional_NonDirectional* current_monowave_class_ptr,int array_size)
{
	bidPrice_difference_Directional_D_up_main.resize(array_size);
	bidPrice_difference_Directional_D_up_main_sub_segment.resize(array_size);

	bidPrice_difference_Directional_D_number_moves_up_main.resize(array_size);
	bidPrice_difference_Directional_D_up_main_start.resize(array_size);
	bidPrice_difference_Directional_D_up_main_continuation.resize(array_size);
	bidPrice_difference_Directional_D_up_main_end.resize(array_size);
	bidPrice_difference_Directional_D_up_main_confirmation.resize(array_size);
	// bidPrice_difference_Directional_D_up_degree.resize(array_size);

	//2/5/2021
	bidPrice_difference_Directional_D_up_main_new_price_action_top.resize(array_size);
	bidPrice_difference_Directional_D_up_main_new_price_action_bottom.resize(array_size);

	bidPrice_difference_Directional_D_up_main_segment_time.resize(array_size);
	bidPrice_difference_Directional_D_up_main_top.resize(array_size);
	bidPrice_difference_Directional_D_up_main_bottom.resize(array_size);
	bidPrice_difference_Directional_D_up_main_span.resize(array_size);
	//vectors for central tendency measures
	bidPrice_difference_Directional_D_up_main_sub_segment_mean.resize(array_size);
	bidPrice_difference_Directional_D_up_main_sub_segment_mode.resize(array_size);
	bidPrice_difference_Directional_D_up_main_sub_segment_median.resize(array_size);

	bidPrice_difference_Directional_D_up_main_sub_segment_all_mean.resize(array_size);
	bidPrice_difference_Directional_D_up_main_sub_segment_all_mode.resize(array_size);
	bidPrice_difference_Directional_D_up_main_sub_segment_all_median.resize(array_size);
	bidPrice_difference_Directional_D_up_main_sub_segment_mean[0] = 0;
	bidPrice_difference_Directional_D_up_main_sub_segment_mode[0] = 0;
	bidPrice_difference_Directional_D_up_main_sub_segment_median[0] = 0;

	bidPrice_difference_Directional_D_up_main_sub_segment_all_mean[0] = 0;
	bidPrice_difference_Directional_D_up_main_sub_segment_all_mode[0] = 0;
	bidPrice_difference_Directional_D_up_main_sub_segment_all_median[0] = 0;

	//prepare_vectors_begining_of_data 
	bidPrice_difference_Directional_D_up_main[0] = 0;
	bidPrice_difference_Directional_D_up_main_sub_segment[0] = 0;

	bidPrice_difference_Directional_D_number_moves_up_main[0] = 0;
	bidPrice_difference_Directional_D_up_main_start[0] = 0;
	bidPrice_difference_Directional_D_up_main_continuation[0] = 0;
	bidPrice_difference_Directional_D_up_main_end[0] = 0;
	bidPrice_difference_Directional_D_up_main_confirmation[0] = 0;
	//bidPrice_difference_Directional_D_up_degree[ 0] = 0;
	//2/5/2021	 
	bidPrice_difference_Directional_D_up_main_new_price_action_top[0] = 0;
	bidPrice_difference_Directional_D_up_main_new_price_action_bottom[0] = 0;

	bidPrice_difference_Directional_D_up_main_segment_time[0] = 0;
	bidPrice_difference_Directional_D_up_main_top[0] = 0;
	bidPrice_difference_Directional_D_up_main_bottom[0] = 0;
	bidPrice_difference_Directional_D_up_main_span[0] = 0;

	
}

Directional_D_down_main::Directional_D_down_main(csv_Directional_NonDirectional* current_monowave_class_ptr, int array_size)
{
	bidPrice_difference_Directional_D_down_main.resize(array_size);
	bidPrice_difference_Directional_D_down_main_sub_segment.resize(array_size);

	bidPrice_difference_Directional_D_number_moves_down_main.resize(array_size);
	bidPrice_difference_Directional_D_down_main_start.resize(array_size);
	bidPrice_difference_Directional_D_down_main_continuation.resize(array_size);
	bidPrice_difference_Directional_D_down_main_end.resize(array_size);
	bidPrice_difference_Directional_D_down_main_confirmation.resize(array_size);
	// bidPrice_difference_Directional_D_down_degree.resize(array_size);
	//2/5/2021
	bidPrice_difference_Directional_D_down_main_new_price_action_top.resize(array_size);
	bidPrice_difference_Directional_D_down_main_new_price_action_bottom.resize(array_size);

	bidPrice_difference_Directional_D_down_main_segment_time.resize(array_size);
	bidPrice_difference_Directional_D_down_main_top.resize(array_size);
	bidPrice_difference_Directional_D_down_main_bottom.resize(array_size);
	bidPrice_difference_Directional_D_down_main_span.resize(array_size);

	//vectors for central tendency measures
	bidPrice_difference_Directional_D_down_main_sub_segment_mean.resize(array_size);
	bidPrice_difference_Directional_D_down_main_sub_segment_mode.resize(array_size);
	bidPrice_difference_Directional_D_down_main_sub_segment_median.resize(array_size);

	bidPrice_difference_Directional_D_down_main_sub_segment_all_mean.resize(array_size);
	bidPrice_difference_Directional_D_down_main_sub_segment_all_mode.resize(array_size);
	bidPrice_difference_Directional_D_down_main_sub_segment_all_median.resize(array_size);
	bidPrice_difference_Directional_D_down_main_sub_segment_mean[0] = 0;
	bidPrice_difference_Directional_D_down_main_sub_segment_mode[0] = 0;
	bidPrice_difference_Directional_D_down_main_sub_segment_median[0] = 0;

	bidPrice_difference_Directional_D_down_main_sub_segment_all_mean[0] = 0;
	bidPrice_difference_Directional_D_down_main_sub_segment_all_mode[0] = 0;
	bidPrice_difference_Directional_D_down_main_sub_segment_all_median[0] = 0;
	//prepare_vectors_begining_of_data 
	bidPrice_difference_Directional_D_down_main[0] = 0;
	bidPrice_difference_Directional_D_down_main_sub_segment[0] = 0;

	bidPrice_difference_Directional_D_number_moves_down_main[0] = 0;
	bidPrice_difference_Directional_D_down_main_start[0] = 0;
	bidPrice_difference_Directional_D_down_main_continuation[0] = 0;
	bidPrice_difference_Directional_D_down_main_end[0] = 0;
	bidPrice_difference_Directional_D_down_main_confirmation[0] = 0;  
	// bidPrice_difference_Directional_D_down_degree[ 0] = 0;
	//2/5/2021
	bidPrice_difference_Directional_D_down_main_new_price_action_top[0] = 0;
	bidPrice_difference_Directional_D_down_main_new_price_action_bottom[0] = 0;

	bidPrice_difference_Directional_D_down_main_segment_time[0] = 0;
	bidPrice_difference_Directional_D_down_main_top[0] = 0;
	bidPrice_difference_Directional_D_down_main_bottom[0] = 0;
	bidPrice_difference_Directional_D_down_main_span[0] = 0;

}

Directional_D_up_counter::Directional_D_up_counter(csv_Directional_NonDirectional* current_monowave_class_ptr, int array_size)
{
	bidPrice_difference_Directional_D_up_counter.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_sub_segment.resize(array_size);

	bidPrice_difference_Directional_D_number_moves_up_counter.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_start.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_continuation.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_end.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_confirmation.resize(array_size);
	// bidPrice_difference_Directional_D_up_degree.resize(array_size);

	//2/5/2021
	bidPrice_difference_Directional_D_up_counter_new_price_action_top.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_new_price_action_bottom.resize(array_size);

	bidPrice_difference_Directional_D_up_counter_segment_time.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_top.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_bottom.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_span.resize(array_size);

	//vectors for central tendency measures
	bidPrice_difference_Directional_D_up_counter_sub_segment_mean.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_sub_segment_mode.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_sub_segment_median.resize(array_size);

	bidPrice_difference_Directional_D_up_counter_sub_segment_all_mean.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_sub_segment_all_mode.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_sub_segment_all_median.resize(array_size);
	bidPrice_difference_Directional_D_up_counter_sub_segment_mean[0] = 0;
	bidPrice_difference_Directional_D_up_counter_sub_segment_mode[0] = 0;
	bidPrice_difference_Directional_D_up_counter_sub_segment_median[0] = 0;

	bidPrice_difference_Directional_D_up_counter_sub_segment_all_mean[0] = 0;
	bidPrice_difference_Directional_D_up_counter_sub_segment_all_mode[0] = 0;
	bidPrice_difference_Directional_D_up_counter_sub_segment_all_median[0] = 0;
	//prepare_vectors_begining_of_data 
	bidPrice_difference_Directional_D_up_counter[0] = 0;
	bidPrice_difference_Directional_D_up_counter_sub_segment[0] = 0;

	bidPrice_difference_Directional_D_number_moves_up_counter[0] = 0;
	bidPrice_difference_Directional_D_up_counter_start[0] = 0;
	bidPrice_difference_Directional_D_up_counter_continuation[0] = 0;
	bidPrice_difference_Directional_D_up_counter_end[0] = 0;
	bidPrice_difference_Directional_D_up_counter_confirmation[0] = 0;  
	//bidPrice_difference_Directional_D_up_degree[ 0] = 0;

	//2/5/2021
	bidPrice_difference_Directional_D_up_counter_new_price_action_top[0] = 0;
	bidPrice_difference_Directional_D_up_counter_new_price_action_bottom[0] = 0;

	bidPrice_difference_Directional_D_up_counter_segment_time[0] = 0;
	bidPrice_difference_Directional_D_up_counter_top[0] = 0;
	bidPrice_difference_Directional_D_up_counter_bottom[0] = 0;
	bidPrice_difference_Directional_D_up_counter_span[0] = 0;

}

Directional_D_down_counter::Directional_D_down_counter(csv_Directional_NonDirectional* current_monowave_class_ptr, int array_size)
{
	bidPrice_difference_Directional_D_down_counter.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_sub_segment.resize(array_size);

	bidPrice_difference_Directional_D_number_moves_down_counter.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_start.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_continuation.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_end.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_confirmation.resize(array_size);
	// bidPrice_difference_Directional_D_down_degree.resize(array_size);
	//2/5/2021
	bidPrice_difference_Directional_D_down_counter_new_price_action_top.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_new_price_action_bottom.resize(array_size);

	bidPrice_difference_Directional_D_down_counter_segment_time.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_top.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_bottom.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_span.resize(array_size);
	//vectors for central tendency measures
	bidPrice_difference_Directional_D_down_counter_sub_segment_mean.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_sub_segment_mode.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_sub_segment_median.resize(array_size);

	bidPrice_difference_Directional_D_down_counter_sub_segment_all_mean.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_sub_segment_all_mode.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_sub_segment_all_median.resize(array_size);
	bidPrice_difference_Directional_D_down_counter_sub_segment_mean[0] = 0;
	bidPrice_difference_Directional_D_down_counter_sub_segment_mode[0] = 0;
	bidPrice_difference_Directional_D_down_counter_sub_segment_median[0] = 0;

	bidPrice_difference_Directional_D_down_counter_sub_segment_all_mean[0] = 0;
	bidPrice_difference_Directional_D_down_counter_sub_segment_all_mode[0] = 0;
	bidPrice_difference_Directional_D_down_counter_sub_segment_all_median[0] = 0;
	//prepare_vectors_begining_of_data 
	bidPrice_difference_Directional_D_down_counter[0] = 0;
	bidPrice_difference_Directional_D_down_counter_sub_segment[0] = 0;

	bidPrice_difference_Directional_D_number_moves_down_counter[0] = 0;
	bidPrice_difference_Directional_D_down_counter_start[0] = 0;
	bidPrice_difference_Directional_D_down_counter_continuation[0] = 0;
	bidPrice_difference_Directional_D_down_counter_end[0] = 0;
	bidPrice_difference_Directional_D_down_counter_confirmation[0] = 0;  
	// bidPrice_difference_Directional_D_down_degree[ 0] = 0;
	//2/5/2021
	bidPrice_difference_Directional_D_down_counter_new_price_action_top[0] = 0;
	bidPrice_difference_Directional_D_down_counter_new_price_action_bottom[0] = 0;

	bidPrice_difference_Directional_D_down_counter_segment_time[0] = 0;
	bidPrice_difference_Directional_D_down_counter_top[0] = 0;
	bidPrice_difference_Directional_D_down_counter_bottom[0] = 0;
	bidPrice_difference_Directional_D_down_counter_span[0] = 0;

}

NonDirectional_ND_up_main::NonDirectional_ND_up_main(csv_Directional_NonDirectional* current_monowave_class_ptr, int array_size)
{
	bidPrice_difference_NonDirectional_ND_up_main.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_sub_segment.resize(array_size);

	bidPrice_difference_NonDirectional_ND_number_moves_up_main.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_start.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_continuation.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_end.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_confirmation.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_new_price_action_top.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_new_price_action_bottom.resize(array_size);

	// bidPrice_difference_NonDirectional_ND_up_degree.resize(array_size);
	//2/5/2021
	bidPrice_difference_NonDirectional_ND_up_main_new_price_action_top[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_new_price_action_bottom[0] = 0;

	bidPrice_difference_NonDirectional_ND_up_main_segment_time.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_top.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_bottom.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_span.resize(array_size);
	//vectors for central tendency measures
	bidPrice_difference_NonDirectional_ND_up_main_sub_segment_mean.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_sub_segment_mode.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_sub_segment_median.resize(array_size);

	bidPrice_difference_NonDirectional_ND_up_main_sub_segment_all_mean.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_sub_segment_all_mode.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_sub_segment_all_median.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_main_sub_segment_mean[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_sub_segment_mode[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_sub_segment_median[0] = 0;

	bidPrice_difference_NonDirectional_ND_up_main_sub_segment_all_mean[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_sub_segment_all_mode[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_sub_segment_all_median[0] = 0;
	//prepare_vectors_begining_of_data 
	bidPrice_difference_NonDirectional_ND_up_main[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_sub_segment[0] = 0;

	bidPrice_difference_NonDirectional_ND_number_moves_up_main[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_start[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_continuation[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_end[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_confirmation[0] = 0;  
	// bidPrice_difference_NonDirectional_ND_up_degree[ 0] = 0;
	//2/5/2021
	bidPrice_difference_NonDirectional_ND_up_main_segment_time[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_top[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_bottom[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_main_span[0] = 0;
}

NonDirectional_ND_down_main::NonDirectional_ND_down_main(csv_Directional_NonDirectional* current_monowave_class_ptr, int array_size)
{
	bidPrice_difference_NonDirectional_ND_down_main.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_sub_segment.resize(array_size);

	bidPrice_difference_NonDirectional_ND_number_moves_down_main.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_start.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_continuation.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_end.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_confirmation.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_new_price_action_top.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_new_price_action_bottom.resize(array_size);

	// bidPrice_difference_NonDirectional_ND_down_degree.resize(array_size);
	//2/5/2021
	bidPrice_difference_NonDirectional_ND_down_main_new_price_action_top[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_new_price_action_bottom[0] = 0;

	bidPrice_difference_NonDirectional_ND_down_main_segment_time.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_top.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_bottom.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_span.resize(array_size);
	//vectors for central tendency measures
	bidPrice_difference_NonDirectional_ND_down_main_sub_segment_mean.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_sub_segment_mode.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_sub_segment_median.resize(array_size);

	bidPrice_difference_NonDirectional_ND_down_main_sub_segment_all_mean.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_sub_segment_all_mode.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_sub_segment_all_median.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_main_sub_segment_mean[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_sub_segment_mode[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_sub_segment_median[0] = 0;

	bidPrice_difference_NonDirectional_ND_down_main_sub_segment_all_mean[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_sub_segment_all_mode[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_sub_segment_all_median[0] = 0;
	//prepare_vectors_begining_of_data 
	bidPrice_difference_NonDirectional_ND_down_main[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_sub_segment[0] = 0;

	bidPrice_difference_NonDirectional_ND_number_moves_down_main[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_start[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_continuation[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_end[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_confirmation[0] = 0;  
	// bidPrice_difference_NonDirectional_ND_down_degree[ 0] = 0;
	//2/5/2021
	bidPrice_difference_NonDirectional_ND_down_main_segment_time[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_top[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_bottom[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_main_span[0] = 0;
}

NonDirectional_ND_up_counter::NonDirectional_ND_up_counter(csv_Directional_NonDirectional* current_monowave_class_ptr, int array_size)
{
	bidPrice_difference_NonDirectional_ND_up_counter.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment.resize(array_size);

	bidPrice_difference_NonDirectional_ND_number_moves_up_counter.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_start.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_continuation.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_end.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_confirmation.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_new_price_action_top.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_new_price_action_bottom.resize(array_size);

	// bidPrice_difference_NonDirectional_ND_up_degree.resize(array_size);
	//2/5/2021
	bidPrice_difference_NonDirectional_ND_up_counter_new_price_action_top[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_new_price_action_bottom[0] = 0;

	bidPrice_difference_NonDirectional_ND_up_counter_segment_time.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_top.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_bottom.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_span.resize(array_size);
	//vectors for central tendency measures
	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_mean.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_mode.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_median.resize(array_size);

	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_all_mean.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_all_mode.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_all_median.resize(array_size);
	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_mean[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_mode[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_median[0] = 0;

	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_all_mean[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_all_mode[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_all_median[0] = 0;
	//prepare_vectors_begining_of_data 
	bidPrice_difference_NonDirectional_ND_up_counter[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_sub_segment[0] = 0;

	bidPrice_difference_NonDirectional_ND_number_moves_up_counter[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_start[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_continuation[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_end[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_confirmation[0] = 0;  
	// bidPrice_difference_NonDirectional_ND_up_degree[ 0] = 0;
	//2/5/2021
	bidPrice_difference_NonDirectional_ND_up_counter_segment_time[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_top[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_bottom[0] = 0;
	bidPrice_difference_NonDirectional_ND_up_counter_span[0] = 0;
}

NonDirectional_ND_down_counter::NonDirectional_ND_down_counter(csv_Directional_NonDirectional* current_monowave_class_ptr, int array_size)
{
	bidPrice_difference_NonDirectional_ND_down_counter.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment.resize(array_size);

	bidPrice_difference_NonDirectional_ND_number_moves_down_counter.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_start.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_continuation.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_end.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_confirmation.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_new_price_action_top.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_new_price_action_bottom.resize(array_size);

	// bidPrice_difference_NonDirectional_ND_down_degree.resize(array_size);
	//2/5/2021
	bidPrice_difference_NonDirectional_ND_down_counter_segment_time.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_top.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_bottom.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_span.resize(array_size);
	//vectors for central tendency measures
	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_mean.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_mode.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_median.resize(array_size);

	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_all_mean.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_all_mode.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_all_median.resize(array_size);
	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_mean[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_mode[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_median[0] = 0;

	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_all_mean[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_all_mode[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_all_median[0] = 0;
	//prepare_vectors_begining_of_data 
	bidPrice_difference_NonDirectional_ND_down_counter[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_sub_segment[0] = 0;

	bidPrice_difference_NonDirectional_ND_number_moves_down_counter[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_start[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_continuation[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_end[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_confirmation[0] = 0;  
	// bidPrice_difference_NonDirectional_ND_down_degree[ 0] = 0;
	//2/5/2021
	bidPrice_difference_NonDirectional_ND_down_counter_new_price_action_top[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_new_price_action_bottom[0] = 0;

	bidPrice_difference_NonDirectional_ND_down_counter_segment_time[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_top[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_bottom[0] = 0;
	bidPrice_difference_NonDirectional_ND_down_counter_span[0] = 0;
}

	