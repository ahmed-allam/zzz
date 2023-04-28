#include "Directional_NonDirectional_degree_class.h"


//__host__
directional_nondirectional_degree_class::directional_nondirectional_degree_class(csv_Directional_NonDirectional* current_monowave_class_ptr, int degree_count)
	//array_size using bidPrice.size() indicate that all degrees will have same size as ticks So we decide to repeat degree number for all members of same larger degree segment in the larger degree vector
	:array_size(current_monowave_class_ptr->bidPrice.size()),
	 Multi_Segment_Same_Direction(current_monowave_class_ptr,  array_size),
	 Directional_D_up_main(current_monowave_class_ptr, array_size),
	 Directional_D_down_main(current_monowave_class_ptr, array_size),
	 Directional_D_up_counter(current_monowave_class_ptr, array_size),
	 Directional_D_down_counter(current_monowave_class_ptr, array_size),
	 NonDirectional_ND_up_main(current_monowave_class_ptr, array_size),
	 NonDirectional_ND_down_main(current_monowave_class_ptr, array_size),
	 NonDirectional_ND_up_counter(current_monowave_class_ptr, array_size),
	 NonDirectional_ND_down_counter(current_monowave_class_ptr, array_size)
{	
	degree_count = degree_count;
	
	//2/5/2021
	bidPrice_difference_undetermined_degree.resize(array_size);
	bidPrice_difference_undetermined_price_difference_move.resize(array_size);

}