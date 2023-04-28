#ifndef DIRECTIONAL_NONDIRECTIONAL_SUBCLASSES
#define DIRECTIONAL_NONDIRECTIONAL_SUBCLASSES
#include <vector>

class csv_Directional_NonDirectional;
class Multi_Segment_Same_Direction
{
public:
	//we need to make another vector for bidPrice_difference_move_start_MS containing number of price difference moves related to move start"for cases of same direction multiple successive moves"
	std::vector<int> bidPrice_difference_move_start_MS_number_of_moves;
	std::vector<int> bidPrice_difference_move_start_MS;
	std::vector<int> bidPrice_difference_multi_segment_same_direction;
public:
	//Multi_Segment_Same_Direction();
	Multi_Segment_Same_Direction(csv_Directional_NonDirectional*, int array_size);
};

class Directional_D_up_main
{
public:
	int Directional_D_up_main_m,
		Directional_D_number_moves_up_main_m;//number of moves of current up direction
	int& identifier_m   = Directional_D_up_main_m;
	int& number_moves_m = Directional_D_number_moves_up_main_m;
public:
	std::vector<int> bidPrice_difference_Directional_D_up_main;
	std::vector<int> bidPrice_difference_Directional_D_up_main_sub_segment;

	std::vector<int> bidPrice_difference_Directional_D_number_moves_up_main;
	std::vector<int> bidPrice_difference_Directional_D_up_main_start;
	std::vector<int> bidPrice_difference_Directional_D_up_main_continuation;
	std::vector<int> bidPrice_difference_Directional_D_up_main_end;
	std::vector<int> bidPrice_difference_Directional_D_up_main_confirmation;
	//std::vector<int> bidPrice_difference_Directional_D_up_degree;

	//2/5/2021
	std::vector<int> bidPrice_difference_Directional_D_up_main_new_price_action_top;
	std::vector<int> bidPrice_difference_Directional_D_up_main_new_price_action_bottom;

	std::vector<int> bidPrice_difference_Directional_D_up_main_segment_time;
	std::vector<int> bidPrice_difference_Directional_D_up_main_top;
	std::vector<int> bidPrice_difference_Directional_D_up_main_bottom;
	std::vector<int> bidPrice_difference_Directional_D_up_main_span;	

public:
	std::vector<int>& identifier       = bidPrice_difference_Directional_D_up_main;
	std::vector<int>& sub_segment = bidPrice_difference_Directional_D_up_main_sub_segment;

	std::vector<int>& number_moves     = bidPrice_difference_Directional_D_number_moves_up_main;
	std::vector<int>& start            = bidPrice_difference_Directional_D_up_main_start;
	std::vector<int>& continuation     = bidPrice_difference_Directional_D_up_main_continuation;
	std::vector<int>& end              = bidPrice_difference_Directional_D_up_main_end;
	std::vector<int>& confirmation     = bidPrice_difference_Directional_D_up_main_confirmation;
	//std::vector<int> bidPrice_difference_Directional_D_up_degree;

	//2/5/2021
	std::vector<int>& new_price_action_top = bidPrice_difference_Directional_D_up_main_new_price_action_top;
	std::vector<int>& new_price_action_bottom = bidPrice_difference_Directional_D_up_main_new_price_action_bottom;

	std::vector<int>& segment_time     = bidPrice_difference_Directional_D_up_main_segment_time;
	std::vector<int>& top              = bidPrice_difference_Directional_D_up_main_top;
	std::vector<int>& bottom           = bidPrice_difference_Directional_D_up_main_bottom;
	std::vector<int>& span             = bidPrice_difference_Directional_D_up_main_span;

	//vectors for central tendency measures
	std::vector<int> bidPrice_difference_Directional_D_up_main_sub_segment_mean;
	std::vector<int> bidPrice_difference_Directional_D_up_main_sub_segment_mode;
	std::vector<int> bidPrice_difference_Directional_D_up_main_sub_segment_median;

	std::vector<int> bidPrice_difference_Directional_D_up_main_sub_segment_all_mean;
	std::vector<int> bidPrice_difference_Directional_D_up_main_sub_segment_all_mode;
	std::vector<int> bidPrice_difference_Directional_D_up_main_sub_segment_all_median;
	// references for vectors for central tendency measures
	std::vector<int>& sub_segment_mean =bidPrice_difference_Directional_D_up_main_sub_segment_mean;//it should be vector of double
	std::vector<int>& sub_segment_mode =bidPrice_difference_Directional_D_up_main_sub_segment_mode;
	std::vector<int>& sub_segment_median =bidPrice_difference_Directional_D_up_main_sub_segment_median;

	std::vector<int>& sub_segment_all_mean =bidPrice_difference_Directional_D_up_main_sub_segment_all_mean;
	std::vector<int>& sub_segment_all_mode =bidPrice_difference_Directional_D_up_main_sub_segment_all_mode;
	std::vector<int>& sub_segment_all_median =bidPrice_difference_Directional_D_up_main_sub_segment_all_median;

public:
	//Directional_D_up_main();
	Directional_D_up_main(csv_Directional_NonDirectional*, int array_size);
};

class Directional_D_down_main
{
public:
	int Directional_D_down_main_m,
		Directional_D_number_moves_down_main_m;//number of moves of current down direction
	int& identifier_m = Directional_D_down_main_m;
	int& number_moves_m = Directional_D_number_moves_down_main_m;
public:
	std::vector<int> bidPrice_difference_Directional_D_down_main;
	std::vector<int> bidPrice_difference_Directional_D_down_main_sub_segment;

	std::vector<int> bidPrice_difference_Directional_D_number_moves_down_main;
	std::vector<int> bidPrice_difference_Directional_D_down_main_start;
	std::vector<int> bidPrice_difference_Directional_D_down_main_continuation;
	std::vector<int> bidPrice_difference_Directional_D_down_main_end;
	std::vector<int> bidPrice_difference_Directional_D_down_main_confirmation;
	//std::vector<int> bidPrice_difference_Directional_D_down_degree;
	//2/5/2021
	std::vector<int> bidPrice_difference_Directional_D_down_main_new_price_action_top;
	std::vector<int> bidPrice_difference_Directional_D_down_main_new_price_action_bottom;

	std::vector<int> bidPrice_difference_Directional_D_down_main_segment_time;
	std::vector<int> bidPrice_difference_Directional_D_down_main_top;
	std::vector<int> bidPrice_difference_Directional_D_down_main_bottom;
	std::vector<int> bidPrice_difference_Directional_D_down_main_span;
	//vectors for central tendency measures
	std::vector<int> bidPrice_difference_Directional_D_down_main_sub_segment_mean;
	std::vector<int> bidPrice_difference_Directional_D_down_main_sub_segment_mode;
	std::vector<int> bidPrice_difference_Directional_D_down_main_sub_segment_median;

	std::vector<int> bidPrice_difference_Directional_D_down_main_sub_segment_all_mean;
	std::vector<int> bidPrice_difference_Directional_D_down_main_sub_segment_all_mode;
	std::vector<int> bidPrice_difference_Directional_D_down_main_sub_segment_all_median;
	// references for vectors for central tendency measures
	std::vector<int>& sub_segment_mean = bidPrice_difference_Directional_D_down_main_sub_segment_mean;
	std::vector<int>& sub_segment_mode = bidPrice_difference_Directional_D_down_main_sub_segment_mode;
	std::vector<int>& sub_segment_median = bidPrice_difference_Directional_D_down_main_sub_segment_median;

	std::vector<int>& sub_segment_all_mean = bidPrice_difference_Directional_D_down_main_sub_segment_all_mean;
	std::vector<int>& sub_segment_all_mode = bidPrice_difference_Directional_D_down_main_sub_segment_all_mode;
	std::vector<int>& sub_segment_all_median = bidPrice_difference_Directional_D_down_main_sub_segment_all_median;
public:
	std::vector<int>& identifier       = bidPrice_difference_Directional_D_down_main;
	std::vector<int>& sub_segment = bidPrice_difference_Directional_D_down_main_sub_segment;

	std::vector<int>& number_moves     = bidPrice_difference_Directional_D_number_moves_down_main;
	std::vector<int>& start            = bidPrice_difference_Directional_D_down_main_start;
	std::vector<int>& continuation     = bidPrice_difference_Directional_D_down_main_continuation;
	std::vector<int>& end              = bidPrice_difference_Directional_D_down_main_end;
	std::vector<int>& confirmation     = bidPrice_difference_Directional_D_down_main_confirmation;
	//std::vector<int> bidPrice_difference_Directional_D_down_degree;
	//2/5/2021
	std::vector<int>& new_price_action_top = bidPrice_difference_Directional_D_down_main_new_price_action_top;
	std::vector<int>& new_price_action_bottom = bidPrice_difference_Directional_D_down_main_new_price_action_bottom;

	std::vector<int>& segment_time     = bidPrice_difference_Directional_D_down_main_segment_time;
	std::vector<int>& top              = bidPrice_difference_Directional_D_down_main_top;
	std::vector<int>& bottom           = bidPrice_difference_Directional_D_down_main_bottom;
	std::vector<int>& span             = bidPrice_difference_Directional_D_down_main_span;

public:
	//Directional_D_down_main();
	Directional_D_down_main(csv_Directional_NonDirectional*, int array_size);
};
class Directional_D_up_counter
{
public:
	int Directional_D_up_counter_m,
		Directional_D_number_moves_up_counter_m;//number of moves of current up direction
	int& identifier_m = Directional_D_up_counter_m;
	int& number_moves_m = Directional_D_number_moves_up_counter_m;
public:

	std::vector<int> bidPrice_difference_Directional_D_up_counter;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_sub_segment;

	std::vector<int> bidPrice_difference_Directional_D_number_moves_up_counter;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_start;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_continuation;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_end;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_confirmation;
	//std::vector<int> bidPrice_difference_Directional_D_up_degree;

	//2/5/2021
	std::vector<int> bidPrice_difference_Directional_D_up_counter_new_price_action_top;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_new_price_action_bottom;

	std::vector<int> bidPrice_difference_Directional_D_up_counter_segment_time;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_top;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_bottom;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_span;
	//vectors for central tendency measures
	std::vector<int> bidPrice_difference_Directional_D_up_counter_sub_segment_mean;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_sub_segment_mode;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_sub_segment_median;

	std::vector<int> bidPrice_difference_Directional_D_up_counter_sub_segment_all_mean;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_sub_segment_all_mode;
	std::vector<int> bidPrice_difference_Directional_D_up_counter_sub_segment_all_median;
	// references for vectors for central tendency measures
	std::vector<int>& sub_segment_mean = bidPrice_difference_Directional_D_up_counter_sub_segment_mean;
	std::vector<int>& sub_segment_mode = bidPrice_difference_Directional_D_up_counter_sub_segment_mode;
	std::vector<int>& sub_segment_median = bidPrice_difference_Directional_D_up_counter_sub_segment_median;

	std::vector<int>& sub_segment_all_mean = bidPrice_difference_Directional_D_up_counter_sub_segment_all_mean;
	std::vector<int>& sub_segment_all_mode = bidPrice_difference_Directional_D_up_counter_sub_segment_all_mode;
	std::vector<int>& sub_segment_all_median = bidPrice_difference_Directional_D_up_counter_sub_segment_all_median;
public:
	std::vector<int>& identifier       = bidPrice_difference_Directional_D_up_counter;
	std::vector<int>& sub_segment = bidPrice_difference_Directional_D_up_counter_sub_segment;

	std::vector<int>& number_moves     = bidPrice_difference_Directional_D_number_moves_up_counter;
	std::vector<int>& start            = bidPrice_difference_Directional_D_up_counter_start;
	std::vector<int>& continuation     = bidPrice_difference_Directional_D_up_counter_continuation;
	std::vector<int>& end              = bidPrice_difference_Directional_D_up_counter_end;
	std::vector<int>& confirmation     = bidPrice_difference_Directional_D_up_counter_confirmation;
	//std::vector<int> bidPrice_difference_Directional_D_down_degree;
	//2/5/2021
	std::vector<int>& new_price_action_top = bidPrice_difference_Directional_D_up_counter_new_price_action_top;
	std::vector<int>& new_price_action_bottom = bidPrice_difference_Directional_D_up_counter_new_price_action_bottom;

	std::vector<int>& segment_time     = bidPrice_difference_Directional_D_up_counter_segment_time;
	std::vector<int>& top              = bidPrice_difference_Directional_D_up_counter_top;
	std::vector<int>& bottom           = bidPrice_difference_Directional_D_up_counter_bottom;
	std::vector<int>& span             = bidPrice_difference_Directional_D_up_counter_span;

public:
	//Directional_D_up_counter();
	Directional_D_up_counter(csv_Directional_NonDirectional*, int array_size);
};
class Directional_D_down_counter
{
public:
	int Directional_D_down_counter_m,
		Directional_D_number_moves_down_counter_m;//number of moves of current down direction
	int& identifier_m = Directional_D_down_counter_m;
	int& number_moves_m = Directional_D_number_moves_down_counter_m;
public:

	std::vector<int> bidPrice_difference_Directional_D_down_counter;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_sub_segment;

	std::vector<int> bidPrice_difference_Directional_D_number_moves_down_counter;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_start;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_continuation;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_end;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_confirmation;
	//std::vector<int> bidPrice_difference_Directional_D_down_degree;
	//2/5/2021
	std::vector<int> bidPrice_difference_Directional_D_down_counter_new_price_action_top;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_new_price_action_bottom;

	std::vector<int> bidPrice_difference_Directional_D_down_counter_segment_time;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_top;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_bottom;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_span;
	//vectors for central tendency measures
	std::vector<int> bidPrice_difference_Directional_D_down_counter_sub_segment_mean;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_sub_segment_mode;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_sub_segment_median;

	std::vector<int> bidPrice_difference_Directional_D_down_counter_sub_segment_all_mean;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_sub_segment_all_mode;
	std::vector<int> bidPrice_difference_Directional_D_down_counter_sub_segment_all_median;
	// references for vectors for central tendency measures
	std::vector<int>& sub_segment_mean = bidPrice_difference_Directional_D_down_counter_sub_segment_mean;
	std::vector<int>& sub_segment_mode = bidPrice_difference_Directional_D_down_counter_sub_segment_mode;
	std::vector<int>& sub_segment_median = bidPrice_difference_Directional_D_down_counter_sub_segment_median;

	std::vector<int>& sub_segment_all_mean = bidPrice_difference_Directional_D_down_counter_sub_segment_all_mean;
	std::vector<int>& sub_segment_all_mode = bidPrice_difference_Directional_D_down_counter_sub_segment_all_mode;
	std::vector<int>& sub_segment_all_median = bidPrice_difference_Directional_D_down_counter_sub_segment_all_median;
public:
	std::vector<int>& identifier       = bidPrice_difference_Directional_D_down_counter;
	std::vector<int>& sub_segment       = bidPrice_difference_Directional_D_down_counter_sub_segment;

	std::vector<int>& number_moves     = bidPrice_difference_Directional_D_number_moves_down_counter;
	std::vector<int>& start            = bidPrice_difference_Directional_D_down_counter_start;
	std::vector<int>& continuation     = bidPrice_difference_Directional_D_down_counter_continuation;
	std::vector<int>& end              = bidPrice_difference_Directional_D_down_counter_end;
	std::vector<int>& confirmation     = bidPrice_difference_Directional_D_down_counter_confirmation;
	//std::vector<int> bidPrice_difference_Directional_D_down_degree;
	//2/5/2021
	std::vector<int>& new_price_action_top = bidPrice_difference_Directional_D_down_counter_new_price_action_top;
	std::vector<int>& new_price_action_bottom = bidPrice_difference_Directional_D_down_counter_new_price_action_bottom;

	std::vector<int>& segment_time	   = bidPrice_difference_Directional_D_down_counter_segment_time;
	std::vector<int>& top              = bidPrice_difference_Directional_D_down_counter_top;
	std::vector<int>& bottom           = bidPrice_difference_Directional_D_down_counter_bottom;
	std::vector<int>& span             = bidPrice_difference_Directional_D_down_counter_span;

public:
	//Directional_D_down_counter();
	Directional_D_down_counter(csv_Directional_NonDirectional*, int array_size);
};
class NonDirectional_ND_up_main
{
public:
	int NonDirectional_ND_up_main_m,
		NonDirectional_ND_number_moves_up_main_m;
	int& identifier_m = NonDirectional_ND_up_main_m;
	int& number_moves_m = NonDirectional_ND_number_moves_up_main_m;
public:

	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_sub_segment;

	std::vector<int> bidPrice_difference_NonDirectional_ND_number_moves_up_main;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_start;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_continuation;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_end;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_confirmation;
	//std::vector<int> bidPrice_difference_NonDirectional_ND_up_degree;
	//2/5/2021
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_new_price_action_top;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_new_price_action_bottom;

	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_segment_time;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_top;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_bottom;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_span;
	//vectors for central tendency measures
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_sub_segment_mean;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_sub_segment_mode;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_sub_segment_median;

	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_sub_segment_all_mean;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_sub_segment_all_mode;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_main_sub_segment_all_median;
	// references for vectors for central tendency measures
	std::vector<int>& sub_segment_mean = bidPrice_difference_NonDirectional_ND_up_main_sub_segment_mean;
	std::vector<int>& sub_segment_mode = bidPrice_difference_NonDirectional_ND_up_main_sub_segment_mode;
	std::vector<int>& sub_segment_median = bidPrice_difference_NonDirectional_ND_up_main_sub_segment_median;

	std::vector<int>& sub_segment_all_mean = bidPrice_difference_NonDirectional_ND_up_main_sub_segment_all_mean;
	std::vector<int>& sub_segment_all_mode = bidPrice_difference_NonDirectional_ND_up_main_sub_segment_all_mode;
	std::vector<int>& sub_segment_all_median = bidPrice_difference_NonDirectional_ND_up_main_sub_segment_all_median;
public:
	std::vector<int>& identifier       = bidPrice_difference_NonDirectional_ND_up_main;
	std::vector<int>& sub_segment = bidPrice_difference_NonDirectional_ND_up_main_sub_segment;

	std::vector<int>& number_moves     = bidPrice_difference_NonDirectional_ND_number_moves_up_main;
	std::vector<int>& start            = bidPrice_difference_NonDirectional_ND_up_main_start;
	std::vector<int>& continuation     = bidPrice_difference_NonDirectional_ND_up_main_continuation;
	std::vector<int>& end              = bidPrice_difference_NonDirectional_ND_up_main_end;
	std::vector<int>& confirmation     = bidPrice_difference_NonDirectional_ND_up_main_confirmation;
	//std::vector<int> bidPrice_difference_Directional_D_down_degree;
	//2/5/2021
	std::vector<int>& new_price_action_top = bidPrice_difference_NonDirectional_ND_up_main_new_price_action_top;
	std::vector<int>& new_price_action_bottom = bidPrice_difference_NonDirectional_ND_up_main_new_price_action_bottom;

	std::vector<int>& segment_time     = bidPrice_difference_NonDirectional_ND_up_main_segment_time;
	std::vector<int>& top              = bidPrice_difference_NonDirectional_ND_up_main_top;
	std::vector<int>& bottom           = bidPrice_difference_NonDirectional_ND_up_main_bottom;
	std::vector<int>& span             = bidPrice_difference_NonDirectional_ND_up_main_span;

public:
	//NonDirectional_ND_up_main();
	NonDirectional_ND_up_main(csv_Directional_NonDirectional*, int array_size);
};
class NonDirectional_ND_down_main
{
public:
	int NonDirectional_ND_down_main_m,
		NonDirectional_ND_number_moves_down_main_m;
	int& identifier_m = NonDirectional_ND_down_main_m;
	int& number_moves_m = NonDirectional_ND_number_moves_down_main_m;
public:

	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_sub_segment;

	std::vector<int> bidPrice_difference_NonDirectional_ND_number_moves_down_main;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_start;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_continuation;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_end;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_confirmation;
	//std::vector<int> bidPrice_difference_NonDirectional_ND_down_degree;
	//2/5/2021	
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_new_price_action_top;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_new_price_action_bottom;

	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_segment_time;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_top;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_bottom;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_span;
	//vectors for central tendency measures
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_sub_segment_mean;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_sub_segment_mode;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_sub_segment_median;

	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_sub_segment_all_mean;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_sub_segment_all_mode;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_main_sub_segment_all_median;
	// references for vectors for central tendency measures
	std::vector<int>& sub_segment_mean = bidPrice_difference_NonDirectional_ND_down_main_sub_segment_mean;
	std::vector<int>& sub_segment_mode = bidPrice_difference_NonDirectional_ND_down_main_sub_segment_mode;
	std::vector<int>& sub_segment_median = bidPrice_difference_NonDirectional_ND_down_main_sub_segment_median;

	std::vector<int>& sub_segment_all_mean = bidPrice_difference_NonDirectional_ND_down_main_sub_segment_all_mean;
	std::vector<int>& sub_segment_all_mode = bidPrice_difference_NonDirectional_ND_down_main_sub_segment_all_mode;
	std::vector<int>& sub_segment_all_median = bidPrice_difference_NonDirectional_ND_down_main_sub_segment_all_median;
public:
	std::vector<int>& identifier       = bidPrice_difference_NonDirectional_ND_down_main;
	std::vector<int>& sub_segment = bidPrice_difference_NonDirectional_ND_down_main_sub_segment;

	std::vector<int>& number_moves     = bidPrice_difference_NonDirectional_ND_number_moves_down_main;
	std::vector<int>& start            = bidPrice_difference_NonDirectional_ND_down_main_start;
	std::vector<int>& continuation     = bidPrice_difference_NonDirectional_ND_down_main_continuation;
	std::vector<int>& end              = bidPrice_difference_NonDirectional_ND_down_main_end;
	std::vector<int>& confirmation     = bidPrice_difference_NonDirectional_ND_down_main_confirmation;
	//std::vector<int> bidPrice_difference_Directional_D_down_degree;
	//2/5/2021
	std::vector<int>& new_price_action_top = bidPrice_difference_NonDirectional_ND_down_main_new_price_action_top;
	std::vector<int>& new_price_action_bottom = bidPrice_difference_NonDirectional_ND_down_main_new_price_action_bottom;

	std::vector<int>& segment_time     = bidPrice_difference_NonDirectional_ND_down_main_segment_time;
	std::vector<int>& top              = bidPrice_difference_NonDirectional_ND_down_main_top;
	std::vector<int>& bottom           = bidPrice_difference_NonDirectional_ND_down_main_bottom;
	std::vector<int>& span             = bidPrice_difference_NonDirectional_ND_down_main_span;
public:
	//NonDirectional_ND_down_main();
	NonDirectional_ND_down_main(csv_Directional_NonDirectional*, int array_size);
};
class NonDirectional_ND_up_counter
{
public:
	int NonDirectional_ND_up_counter_m,
		NonDirectional_ND_number_moves_up_counter_m;
	int& identifier_m = NonDirectional_ND_up_counter_m;
	int& number_moves_m = NonDirectional_ND_number_moves_up_counter_m;
public:

	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_sub_segment;

	std::vector<int> bidPrice_difference_NonDirectional_ND_number_moves_up_counter;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_start;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_continuation;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_end;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_confirmation;
	//std::vector<int> bidPrice_difference_NonDirectional_ND_up_degree;
	//2/5/2021
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_new_price_action_top;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_new_price_action_bottom;

	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_segment_time;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_top;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_bottom;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_span;
	//vectors for central tendency measures
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_mean;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_mode;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_median;

	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_all_mean;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_all_mode;
	std::vector<int> bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_all_median;
	// references for vectors for central tendency measures
	std::vector<int>& sub_segment_mean = bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_mean;
	std::vector<int>& sub_segment_mode = bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_mode;
	std::vector<int>& sub_segment_median = bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_median;

	std::vector<int>& sub_segment_all_mean = bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_all_mean;
	std::vector<int>& sub_segment_all_mode = bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_all_mode;
	std::vector<int>& sub_segment_all_median = bidPrice_difference_NonDirectional_ND_up_counter_sub_segment_all_median;
public:
	std::vector<int>& identifier = bidPrice_difference_NonDirectional_ND_up_counter;
	std::vector<int>& sub_segment = bidPrice_difference_NonDirectional_ND_up_counter_sub_segment;

	std::vector<int>& number_moves     = bidPrice_difference_NonDirectional_ND_number_moves_up_counter;
	std::vector<int>& start            = bidPrice_difference_NonDirectional_ND_up_counter_start;
	std::vector<int>& continuation     = bidPrice_difference_NonDirectional_ND_up_counter_continuation;
	std::vector<int>& end              = bidPrice_difference_NonDirectional_ND_up_counter_end;
	std::vector<int>& confirmation     = bidPrice_difference_NonDirectional_ND_up_counter_confirmation;
	//std::vector<int> bidPrice_difference_Directional_D_down_degree;
	//2/5/2021
	std::vector<int>& new_price_action_top = bidPrice_difference_NonDirectional_ND_up_counter_new_price_action_top;
	std::vector<int>& new_price_action_bottom = bidPrice_difference_NonDirectional_ND_up_counter_new_price_action_bottom;

	std::vector<int>& segment_time     = bidPrice_difference_NonDirectional_ND_up_counter_segment_time;
	std::vector<int>& top              = bidPrice_difference_NonDirectional_ND_up_counter_top;
	std::vector<int>& bottom           = bidPrice_difference_NonDirectional_ND_up_counter_bottom;
	std::vector<int>& span             = bidPrice_difference_NonDirectional_ND_up_counter_span;
public:
	//NonDirectional_ND_up_counter();
	NonDirectional_ND_up_counter(csv_Directional_NonDirectional*, int array_size);

};
class NonDirectional_ND_down_counter
{
public:
	int NonDirectional_ND_down_counter_m,
		NonDirectional_ND_number_moves_down_counter_m;
	int& identifier_m = NonDirectional_ND_down_counter_m;
	int& number_moves_m = NonDirectional_ND_number_moves_down_counter_m;
public:

	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_sub_segment;

	std::vector<int> bidPrice_difference_NonDirectional_ND_number_moves_down_counter;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_start;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_continuation;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_end;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_confirmation;
	//std::vector<int> bidPrice_difference_NonDirectional_ND_down_degree;
	//2/5/2021
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_new_price_action_top;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_new_price_action_bottom;

	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_segment_time;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_top;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_bottom;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_span;
	//vectors for central tendency measures
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_mean;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_mode;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_median;

	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_all_mean;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_all_mode;
	std::vector<int> bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_all_median;
	// references for vectors for central tendency measures
	std::vector<int>& sub_segment_mean = bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_mean;
	std::vector<int>& sub_segment_mode = bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_mode;
	std::vector<int>& sub_segment_median = bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_median;

	std::vector<int>& sub_segment_all_mean = bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_all_mean;
	std::vector<int>& sub_segment_all_mode = bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_all_mode;
	std::vector<int>& sub_segment_all_median = bidPrice_difference_NonDirectional_ND_down_counter_sub_segment_all_median;
public:
	std::vector<int>& identifier       = bidPrice_difference_NonDirectional_ND_down_counter;
	std::vector<int>& sub_segment       = bidPrice_difference_NonDirectional_ND_down_counter_sub_segment;

	std::vector<int>& number_moves     = bidPrice_difference_NonDirectional_ND_number_moves_down_counter;
	std::vector<int>& start            = bidPrice_difference_NonDirectional_ND_down_counter_start;
	std::vector<int>& continuation     = bidPrice_difference_NonDirectional_ND_down_counter_continuation;
	std::vector<int>& end              = bidPrice_difference_NonDirectional_ND_down_counter_end;
	std::vector<int>& confirmation     = bidPrice_difference_NonDirectional_ND_down_counter_confirmation;
	//std::vector<int> bidPrice_difference_Directional_D_down_degree;
	//2/5/2021
	std::vector<int>& new_price_action_top = bidPrice_difference_NonDirectional_ND_down_counter_new_price_action_top;
	std::vector<int>& new_price_action_bottom = bidPrice_difference_NonDirectional_ND_down_counter_new_price_action_bottom;

	std::vector<int>& segment_time     = bidPrice_difference_NonDirectional_ND_down_counter_segment_time;
	std::vector<int>& top              = bidPrice_difference_NonDirectional_ND_down_counter_top;
	std::vector<int>& bottom           = bidPrice_difference_NonDirectional_ND_down_counter_bottom;
	std::vector<int>& span             = bidPrice_difference_NonDirectional_ND_down_counter_span;
public:
	//NonDirectional_ND_down_counter();
	NonDirectional_ND_down_counter(csv_Directional_NonDirectional*, int array_size);
};

#endif //DIRECTIONAL_NONDIRECTIONAL_SUBCLASSES