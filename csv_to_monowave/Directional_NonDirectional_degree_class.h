#ifndef DIRECTIONAL_NONDIRECTIONAL_DEGREE_CLASS
#define DIRECTIONAL_NONDIRECTIONAL_DEGREE_CLASS

#include <vector>
#include "csv_Directional_NonDirectional.h"
#include "Directional_NonDirectional_subclasses.h"

class directional_nondirectional_degree_class :
	public Multi_Segment_Same_Direction,
	public Directional_D_up_main,
	public Directional_D_up_counter,
	public Directional_D_down_main,
	public Directional_D_down_counter,
	public NonDirectional_ND_up_main,
	public NonDirectional_ND_up_counter,
	public NonDirectional_ND_down_main,
	public NonDirectional_ND_down_counter
{
	friend class csv_Directional_NonDirectional;
	int array_size;
	int degree_count;
//private: for qt convenience 11-10-2021
public:
	int move_start_MS,
		move_start_MS_number_of_moves;//incase same direction move with different slopes ???

	int bidPrice_difference_many_differences_var;
	float bidPrice_difference_to_previous_movement_percentage_many_percentages_var;
	
	//2/5/2021
	std::vector<int> bidPrice_difference_undetermined_degree;
	std::vector<int> bidPrice_difference_undetermined_price_difference_move;
public:
	//__host__
	directional_nondirectional_degree_class(csv_Directional_NonDirectional*,int);

	//get begin of move
	//get degree of move
	//get higher or lower degree of move
};
#endif