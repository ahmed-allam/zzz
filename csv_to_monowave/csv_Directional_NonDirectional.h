#ifndef CSV_DIRECTIONAL_NONDIRECTIONAL
#define CSV_DIRECTIONAL_NONDIRECTIONAL
#include "csv_Directional_NonDirectional_general_methods.h"

#include "csv_min_time_with_price_difference.h"

//for DIRECTIONAL_NONDIRECTIONAL_DEGREE_CLASS
#include "Directional_NonDirectional_degree_class.h"
class Worker;
class csv_Directional_NonDirectional:public csv_min_time_with_price_difference
{
public:
	//default constructor
	csv_Directional_NonDirectional();
	csv_Directional_NonDirectional(Worker*);
public:
	friend class directional_nondirectional_degree_class;	
	std::vector<directional_nondirectional_degree_class> D_ND_degree_vec;

public:
	//csv_Directional_NonDirectional();
	//members for csv_Directional_NonDirectional
	//we are at beginning of data
	int Directional_NonDirectional_index = 0;
	std::vector<float> bidPrice_difference_to_previous_movement_percentage;//price difference means tick line
	std::vector<float> bidPrice_difference_tickpartTime_difference_to_previous_movement_percentage;

	//9-9-2022
	//void prepare_vectors_begining_of_data(int current_degree);
	void prepare_vectors_begining_of_data();

	int current_degree = 0;

public:
	void calculate_price_difference_to_previous_percentage();
	void calculate_tickparttime_difference_to_previous_percentage();

	//now we make methods filling Directional_NonDirectional vectors
	//void give_first_price_difference_tickline_description_movestart_MS_1(int current_degree);
	void give_first_price_difference_tickline_description_movestart_MS_1();

	//now I shall fill in bidPrice_difference_multi_segment_same_direction
	//void fill_bidPrice_difference_multi_segment_same_direction(int current_degree, int Directional_NonDirectional_index);
	void fill_bidPrice_difference_multi_segment_same_direction();

	//I ll make if condition in for loop for Directional_NonDirectional_index=1
	//general start functions
	// 
	//i might make template but it will require to change names of all degree subclasses
	//So I will not use template
	// MODIFICATION: I WILL MAKE TYPEDEF FOR MEMBERS OF DEGREE SUBCLASSES SO THAT WE CAN USE TEMPLATES
	template<class D_ND_subclass> 
	void start_D_ND_identifier(int identifier);

	//here we record the point of start using the number we gave to it as its identifier
	template<class D_ND_subclass>
	void start_D_ND_record_point_start();
	
	//here we record total time of movement
	template<class D_ND_subclass>
	void start_D_ND_record_total_time_movement();

	//here we record top price point in current movement
	template<class D_ND_subclass>
	void start_D_ND_record_top_price_current_movement();

	//here we record bottom price point in current movement
	template<class D_ND_subclass>
	void start_D_ND_record_bottom_price_current_movement();


	//here we record the new_price_action_top 
	template<class D_ND_subclass>
	void start_D_ND_record_new_price_action_top();

	//here we record the new_price_action_bottom
	template<class D_ND_subclass>
	void start_D_ND_record_new_price_action_bottom();

	//here we record span between top and bottom points of ND_up_main
	template<class D_ND_subclass>
	void start_D_ND_record_span_top_bottom();

	//start at begin of data
	//void start_begin_data(int current_degree, int Directional_NonDirectional_index);
	void start_begin_data();

	//void start_begin_data_Zero_Move_as_NonDirectional(int current_degree, int Directional_NonDirectional_index);
	void start_begin_data_Zero_Move_as_NonDirectional();

	//the start move at begin of data could be Directional or NonDirectional
	//void start_begin_data_Directional(int current_degree, int Directional_NonDirectional_index);
	void start_begin_data_Directional();

	//void start_begin_data_NonDirectional(int current_degree, int Directional_NonDirectional_index);
	void start_begin_data_NonDirectional();

	//the Directional could be up or down
	//void start_begin_data_Directional_Up(int current_degree, int Directional_NonDirectional_index);
	void start_begin_data_Directional_Up();

	//void start_begin_data_Directional_Down(int current_degree, int Directional_NonDirectional_index);
	void start_begin_data_Directional_Down();

	//the NonDirectional could be zero move or less than 45 degree move

	//start after finished movement
	//void start_after_finished_movement(int current_degree, int Directional_NonDirectional_index);
	void start_after_finished_movement();

	//start at one lesser degree
	//start at one greater degree
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//here we make methods to calculate measures of central tendency "MEAN MEDIAN MODE"
	//calculate mean of each subsegmet of movement
	template<class D_ND_subclass>
	void calculate_mean_each_subsegmet_movement();
	//calculate mean of all subsegmets of movement
	//calculate median of each subsegmet of movement
	//calculate median of all subsegmets of movement
	//calculate mode of each subsegmet of movement
	//calculate mode of all subsegmets of movement
};
#endif //CSV_DIRECTIONAL_NONDIRECTIONAL
