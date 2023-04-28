#include "csv_Directional_NonDirectional.h"
#include "../Worker.h"
using namespace boost::chrono;

//__host__ 
//void csv_Directional_NonDirectional::prepare_vectors_begining_of_data(int current_degree)
void csv_Directional_NonDirectional::prepare_vectors_begining_of_data()

{
	
	bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = 0;
	bidPrice_difference_tickpartTime_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = 0;
	//we use degree 0 class >>>>no we use all drgree classes making thier first value =0 as this is 1st price,no difference is made ,nothing started yet
	//so now current_degree has no use here
	//2/5/2021
	for (int degree_count = -10; degree_count < 10; degree_count++)
	{
		D_ND_degree_vec[degree_count].
			bidPrice_difference_undetermined_degree[Directional_NonDirectional_index] = 0;
		D_ND_degree_vec[degree_count].
		bidPrice_difference_undetermined_price_difference_move[Directional_NonDirectional_index] = 0;
	}
}
void csv_Directional_NonDirectional::calculate_price_difference_to_previous_percentage()
{
	start = high_resolution_clock::now();

	for (std::vector<int>::iterator it = bidPrice_difference.begin(); it != bidPrice_difference.end(); ++it)
	{
		Directional_NonDirectional_index = std::distance(bidPrice_difference.begin(), it);		
		//there is no logic for D and ND yet ?????11-5-2021
		//now we have no percentage because this is the 2nd price and it forms 1st price difference with no previous price difference to compare to
		//note that we apply to tickpartTime_difference too here not in the next tickpartTime function then we start tickpartTime function from index 2
		if (Directional_NonDirectional_index == 1)
		{
			bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = 0;
			bidPrice_difference_tickpartTime_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = 0;
		}
		if (Directional_NonDirectional_index > 1)
		{
			//if ((sgn(*it) != 0) && (Directional_NonDirectional_index != 0) && (sgn(*(it - 1)) != 0))
			if ((sgn(*it) != 0) && (sgn(*(it - 1)) != 0))
			{
				bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = (((*it) / *(it - 1)) * 100);//price difference means tick line
			}
			//else if ((sgn(*it) != 0) && (Directional_NonDirectional_index != 0) && (sgn(*(it - 1)) == 0))
			else if ((sgn(*it) != 0) && (sgn(*(it - 1)) == 0))
			{
				bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = (std::numeric_limits<float>::max());//price difference means tick line "std::numeric_limits<double>::infinity()"
			}
			//else if ((sgn(*it) == 0) && (Directional_NonDirectional_index != 0) && (sgn(*(it - 1)) == 0))
			else if ((sgn(*it) == 0) && (sgn(*(it - 1)) == 0))
			{
				//look at line 203
			}
		}
	}
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_Directional_NonDirectional::calculate_tickparttime_difference_to_previous_percentage()
{
	//the next for loop calculate tickparttime difference percentage
	start = high_resolution_clock::now();
	//we start tickpartTime function from index 2 as we did index 1 in calculate_price_difference_to_previous_percentage
	for (std::vector<int>::iterator it = tickpartTime_difference.begin() + 2; it != tickpartTime_difference.end(); ++it)
	{
		Directional_NonDirectional_index = std::distance(bidPrice_difference.begin(), it);
		bidPrice_difference_tickpartTime_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = (((*it) / *(it - 1)) * 100);//price difference means tick line
	}
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

//now we make methods filling Directional_NonDirectional vectors
//void csv_Directional_NonDirectional::give_first_price_difference_tickline_description_movestart_MS_1(int current_degree)
void csv_Directional_NonDirectional::give_first_price_difference_tickline_description_movestart_MS_1()

{
	start = high_resolution_clock::now();

	D_ND_degree_vec[current_degree].
		move_start_MS = 1;
	D_ND_degree_vec[current_degree].
		move_start_MS_number_of_moves = 1;

	D_ND_degree_vec[current_degree].
		Directional_D_up_main_m = 0;
	D_ND_degree_vec[current_degree].
		Directional_D_number_moves_up_main_m = 0;//number of moves of current up D_ND_degree_vec[current_degree].Direction
	D_ND_degree_vec[current_degree].
		Directional_D_down_main_m = 0;
	D_ND_degree_vec[current_degree].
		Directional_D_number_moves_down_main_m = 0;//number of moves of current down D_ND_degree_vec[current_degree].Direction
	D_ND_degree_vec[current_degree].
		Directional_D_up_counter_m = 0;
	D_ND_degree_vec[current_degree].
		Directional_D_number_moves_up_counter_m = 0;//number of moves of current up D_ND_degree_vec[current_degree].Direction
	D_ND_degree_vec[current_degree].
		Directional_D_down_counter_m = 0;
	D_ND_degree_vec[current_degree].
		Directional_D_number_moves_down_counter_m = 0;//number of moves of current down direction
	D_ND_degree_vec[current_degree].
		NonDirectional_ND_up_main_m = 0;
	D_ND_degree_vec[current_degree].
		NonDirectional_ND_number_moves_up_main_m = 0;
	D_ND_degree_vec[current_degree].
		NonDirectional_ND_down_main_m = 0;
	D_ND_degree_vec[current_degree].
		NonDirectional_ND_number_moves_down_main_m = 0;
	D_ND_degree_vec[current_degree].
		NonDirectional_ND_up_counter_m = 0;
	D_ND_degree_vec[current_degree].
		NonDirectional_ND_number_moves_up_counter_m = 0;
	D_ND_degree_vec[current_degree].
		NonDirectional_ND_down_counter_m = 0;
	D_ND_degree_vec[current_degree].
		NonDirectional_ND_number_moves_down_counter_m = 0;

	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
//void csv_Directional_NonDirectional::fill_bidPrice_difference_multi_segment_same_direction(int current_degree, int Directional_NonDirectional_index)
void csv_Directional_NonDirectional::fill_bidPrice_difference_multi_segment_same_direction()
{
	//if (Directional_NonDirectional_index == 0 || Directional_NonDirectional_index == 1) we already start for loop at index 1
	if (Directional_NonDirectional_index == 1)
	{
		D_ND_degree_vec[current_degree].
			bidPrice_difference_multi_segment_same_direction[Directional_NonDirectional_index] = 0;
	}
	if ((sgn(*it) == sgn(*(it - 1))) && (Directional_NonDirectional_index >= 2))
	{
		D_ND_degree_vec[current_degree].
			bidPrice_difference_multi_segment_same_direction[Directional_NonDirectional_index] =
			D_ND_degree_vec[current_degree].
			bidPrice_difference_multi_segment_same_direction[Directional_NonDirectional_index - 1] + 1;
	}
}

//default constructor
csv_Directional_NonDirectional::csv_Directional_NonDirectional()
	: csv_min_time_with_price_difference()
{

}
csv_Directional_NonDirectional::csv_Directional_NonDirectional(Worker* workerPtr)
	: csv_min_time_with_price_difference(workerPtr)
{
	plot_flag = csv_directional_nondirectional_degree_class_m;

	//21-2-2021 I make DIRECTIONAL_NONDIRECTIONAL_DEGREE_CLASS which has the following variables
	//I will make array of 21 instances of directional_nondirectional_degree_class
	for (int degree_count = -10; degree_count < 10; degree_count++)
	{
		// directional_nondirectional_degree_class directional_nondirectional_degree_class(degree_count);
		D_ND_degree_vec.push_back(directional_nondirectional_degree_class(this, degree_count));
	}

	bidPrice_difference_to_previous_movement_percentage.resize(bidPrice.size());
	bidPrice_difference_tickpartTime_difference_to_previous_movement_percentage.resize(bidPrice.size());

	current_degree = 0;
	//we are at beginning of data
	if ((Directional_NonDirectional_index == 0))
	{
		//we are at beginning of data
		prepare_vectors_begining_of_data();
	}
	//calculate price difference to previous percentage
	calculate_price_difference_to_previous_percentage();

	//calculate tickparttime difference percentage
	calculate_tickparttime_difference_to_previous_percentage();	
	
	//give first price difference"tick line" description as movestart MS with number 1
	give_first_price_difference_tickline_description_movestart_MS_1();
	
	//now I iterate in bidPrice_difference from element 1"2nd  element"
	for (std::vector<int>::iterator it = bidPrice_difference.begin() +1; it != bidPrice_difference.end(); ++it)
	{
		Directional_NonDirectional_index = std::distance(bidPrice_difference.begin(), it);

		//now I shall fill in bidPrice_difference_multi_segment_same_direction
		fill_bidPrice_difference_multi_segment_same_direction( );

		//I ll make if condition in for loop for Directional_NonDirectional_index=1
		if (Directional_NonDirectional_index == 1)
		{
			//start at begin of data 
			start_begin_data();

		}
		
		if ((sgn(*it) == 0))
		{

			/*
			"we now consider all moves are single moves then we will modify for ranges???">>>i should treat range now
			if ((sgn(*it) != 0) && (Directional_NonDirectional_index != 0) && (sgn(*(it-1)) == 0))//>>>>>>3
				//&& ((*it) > (2.5 * (*(it - 1)))) && (bidPrice_difference[0] == 0))
			{
				//index 0 and all moves of zero move are one less degree than current move

			}
			*/

			//1.start
			//check sign of price difference to determine up or down or sideway
			//this condition treat the case when price data starts with zero move
			if ((sgn(*it) == 0) && (Directional_NonDirectional_index == 1)) //we are in side way move So start ND>>>>5
			{
				
				
			}

			//2.continuation
			//test if current move is continuation for previous same direction move
			if ((sgn(*it) == 0) && (Directional_NonDirectional_index != 1) && (sgn(*(it - 1)) == 0)) //we are in side way move of 0 after sideway move of 0 >>>>>>2
			{
				//11-5-2021 we didnot yet make modifications on zero side way degree according to its time consumption?????????????????

				//we want to merge pricediff[index] and pricediff[index-1]
				D_ND_degree_vec[current_degree].
				bidPrice_difference_move_start_MS[Directional_NonDirectional_index] = D_ND_degree_vec[current_degree].bidPrice_difference_move_start_MS[Directional_NonDirectional_index - 1];
				D_ND_degree_vec[current_degree].
				bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index] = D_ND_degree_vec[current_degree].bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index - 1] + 1;
				//we calculate percentage for both ticklines
				D_ND_degree_vec[current_degree].
				bidPrice_difference_many_differences_var = bidPrice[Directional_NonDirectional_index] - bidPrice[Directional_NonDirectional_index - D_ND_degree_vec[current_degree].bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index]];

				//here we test if previous move several number of moves before, is  0 so we have division by 0 or any other condition where previous price diff was 0
				if (bidPrice_difference[Directional_NonDirectional_index - D_ND_degree_vec[current_degree].bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index]] == 0)
				{
					D_ND_degree_vec[current_degree].
					bidPrice_difference_to_previous_movement_percentage_many_percentages_var = std::numeric_limits<float>::max();
					bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = D_ND_degree_vec[current_degree].bidPrice_difference_to_previous_movement_percentage_many_percentages_var;
				}
				else if (bidPrice_difference[Directional_NonDirectional_index - D_ND_degree_vec[current_degree].bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index]] != 0)
				{
					D_ND_degree_vec[current_degree].
					bidPrice_difference_to_previous_movement_percentage_many_percentages_var = D_ND_degree_vec[current_degree].bidPrice_difference_many_differences_var / bidPrice_difference[Directional_NonDirectional_index - D_ND_degree_vec[current_degree].bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index]];
					bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = D_ND_degree_vec[current_degree].bidPrice_difference_to_previous_movement_percentage_many_percentages_var;
				}

				//now we fill arrays for ND as we consider zero move >> ND at beginning then we can test up or down according to the previous trend of which it is a segment???????????????		
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_up[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up[Directional_NonDirectional_index - 1]);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_number_moves_up[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_number_moves_up[Directional_NonDirectional_index - 1] + 1);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_up_start[Directional_NonDirectional_index] = (0);
				D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_continuation[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up[Directional_NonDirectional_index - 1]);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_up_end[Directional_NonDirectional_index] = (0);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_up_confirmation[Directional_NonDirectional_index] = (0);
				//D_ND_degree_vec[current_degree].
				//bidPrice_difference_NonDirectional_ND_up_degree[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_degree[Directional_NonDirectional_index - 1]);

				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_down[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down[Directional_NonDirectional_index - 1]);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_number_moves_down[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_number_moves_down[Directional_NonDirectional_index - 1] + 1);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_down_start[Directional_NonDirectional_index] = (0);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_down_continuation[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down[Directional_NonDirectional_index - 1]);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_down_end[Directional_NonDirectional_index] = (0);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_down_confirmation[Directional_NonDirectional_index] = (0);
				//D_ND_degree_vec[current_degree].
				//bidPrice_difference_NonDirectional_ND_down_degree[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_degree[Directional_NonDirectional_index - 1]);

			}
			//confirmation
			//we want to confirm either up or down direction of previous first move zero side way at beginning of data
			if ((sgn(*it) != 0) && (Directional_NonDirectional_index != 0) && (sgn(*(it - 1)) == 0))//>>>>>>>3
			{
				//if sign is +ve we keep previous NDup else we keep NDdown
				if ((sgn(*it) == 1)) //work on down move making it zerod
				{
					//find degree of previous move>>>>now I use array of classes each class for single degree
					//Directional_NonDirectional_Degree = (bidPrice_difference_NonDirectional_ND_up_degree[Directional_NonDirectional_index - 1]);
					//loop in degree till current degree
					//for (Directional_NonDirectional_Degree_loop_index = Directional_NonDirectional_Degree; ; ++Directional_NonDirectional_Degree_loop_index)

					//find direction label number of previous move
					D_ND_degree_vec[current_degree].
					Directional_NonDirectional_Label_number = D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up[Directional_NonDirectional_index - 1];
					//find start of previous move
					//here we works on start vector which is always 0 unless the record where start happens so we should for loop from the previous record because it is either 0 if direction started before it or direction number if it is just starting
					for (std::vector<int>::iterator it = D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start.begin() + Directional_NonDirectional_index; it != D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start.begin(); --it)

					{

						if ((*it != D_ND_degree_vec[current_degree].Directional_NonDirectional_Label_number))//( bidPrice_difference_NonDirectional_ND_up_degree[it - bidPrice_difference_NonDirectional_ND_up_start.begin()]== Directional_NonDirectional_Degree))
						{
							continue;
						}
						else if ((*it == D_ND_degree_vec[current_degree].Directional_NonDirectional_Label_number) //&& (bidPrice_difference_NonDirectional_ND_up_degree[it - bidPrice_difference_NonDirectional_ND_up_start.begin()] == Directional_NonDirectional_Degree)
							)

						{
							D_ND_degree_vec[current_degree].
							bidPrice_difference_NonDirectional_ND_up_start_index = it - D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start.begin();
							break;
						}
					}
					//find end of previous move
					for (std::vector<int>::iterator it = D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_end.begin() + Directional_NonDirectional_index; it != D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_end.begin(); --it)

					{
						if (*it != D_ND_degree_vec[current_degree].Directional_NonDirectional_Label_number)
						{
							if ((D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start[it - D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start.begin()] > D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start_index))
							{
								continue;
							}

						 
							else if ((D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start[it - D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start.begin()] == D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start_index))
							{
								//no end for this Directional_NonDirectional_Label_number,so  end  it
								D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_end[(it - 1) - D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_end.begin()] == D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start[D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start_index];

								//zero NDdown from begin of NDup start to current -1
								for (std::vector<int>::iterator it = D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start.begin() + D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start_index; it < D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start.begin() + Directional_NonDirectional_index; it++)
								{
									int index2 = it - D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start.begin();
									D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down[index2] = 0;
									D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_number_moves_down[index2] = 0;
									D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start[index2] = (0);
									D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_continuation[index2] = 0;
									D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_end[index2] = (0);
									D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_confirmation[index2] = (0);
									//D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_degree[index2] = 0;

								}
								goto cnt;
							}

						}
						else if ((*it == D_ND_degree_vec[current_degree].Directional_NonDirectional_Label_number) //&& (bidPrice_difference_NonDirectional_ND_up_degree[it - bidPrice_difference_NonDirectional_ND_up_end.begin()] == Directional_NonDirectional_Degree)
							)
						{
							D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_end_index = it - D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_end.begin();
							break;
						}
					}
					//if it has end then find start of higher degree by one
					//loop to find end
					//if it has no end then end the NDup and zero the NDdown
				cnt:

				}
				else if ((sgn(*it) == -1))
				{
					//find degree of previous move
					//Directional_NonDirectional_Degree = (bidPrice_difference_NonDirectional_ND_down_degree[Directional_NonDirectional_index - 1]);
					//loop in degree till current degree
					//for (Directional_NonDirectional_Degree_loop_index = Directional_NonDirectional_Degree; ; ++Directional_NonDirectional_Degree_loop_index)
					//{
						//find label number of previous move
					D_ND_degree_vec[current_degree].Directional_NonDirectional_Label_number = D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down[Directional_NonDirectional_index - 1];
					//find start of previous move
					for (std::vector<int>::iterator it = D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start.begin() + Directional_NonDirectional_index; it != D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start.begin(); --it)

					{
						if ((*it != D_ND_degree_vec[current_degree].Directional_NonDirectional_Label_number))//( bidPrice_difference_NonDirectional_ND_down_degree[it - bidPrice_difference_NonDirectional_ND_down_start.begin()]== Directional_NonDirectional_Degree))
						{
							continue;
						}
						else if ((*it == D_ND_degree_vec[current_degree].Directional_NonDirectional_Label_number) //&& (bidPrice_difference_NonDirectional_ND_down_degree[it - bidPrice_difference_NonDirectional_ND_down_start.begin()] == Directional_NonDirectional_Degree)
							)

						{
							D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start_index = it - D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start.begin();
							break;
						}
					}
					//find end of previous move
					for (std::vector<int>::iterator it = D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_end.begin() + Directional_NonDirectional_index; it != D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_end.begin(); --it)

					{
						if (*it != D_ND_degree_vec[current_degree].Directional_NonDirectional_Label_number)
						{
							if ((D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start[it - D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start.begin()] > D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start_index))
							{
								continue;
							}

						
							else if ((D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start[it - D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start.begin()] == D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start_index))
							{
								//no end for this Directional_NonDirectional_Label_number,so make test end to it
								D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_end[(it - 1) - D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_end.begin()] == D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start[D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start_index];

								//zero NDup from begin of NDdown start to current -1
								for (std::vector<int>::iterator it = D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start.begin() + D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start_index; it < D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start.begin() + Directional_NonDirectional_index; it++)
								{
									int index2 = it - D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_start.begin();
									D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up[index2] = 0;
									D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_number_moves_up[index2] = 0;
									D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_start[index2] = (0);
									D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_continuation[index2] = 0;
									D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_end[index2] = (0);
									D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_confirmation[index2] = (0);
									//D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_degree[index2] = 0;

								}
								goto cnt;
							}

						}
						else if ((*it == D_ND_degree_vec[current_degree].Directional_NonDirectional_Label_number) //&& (bidPrice_difference_NonDirectional_ND_down_degree[it - bidPrice_difference_NonDirectional_ND_down_end.begin()] == Directional_NonDirectional_Degree)
							)
						{
							D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_end_index = it - D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_down_end.begin();
							break;
						}
					}
					//if it has end then find start of higher degree by one??????????????????????
					//loop to find end
					//if it has no end then end the NDup and zero the NDdown
				cnt:
					//}
				}
			}
			//first we need to get previous move degree
			//int bidPrice_difference_NonDirectional_ND_up_degree_var;
			//end
		}
		if ((sgn(*it) == 1))
		{
			
			//4.end there is no end until Directional_NonDirectional_index is atleast 2
			if (Directional_NonDirectional_index >= 2)
			{
				//end happens after single segment or more than 2 consecutive segments of same direction or 3 segments of alternating direction
				//1 end ?????after single segment???????
				if ((sgn(*it) != sgn(*(it - 1))) && (sgn(*it) != 0))
				{
					//end of Directional move
					if ((bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index] > 100)
						&& (is_Directional(Directional_NonDirectional_index - 1, current_degree)))
					{
						//Directional_NonDirectional_index - 1 ended
						//get the direction up or down of Directional_NonDirectional_index - 1
						if (D_ND_degree_vec[current_degree].
							bidPrice_difference_Directional_D_up[Directional_NonDirectional_index-1]!=0)
						{
							//it is up
							//put in end array the label of Dup of Directional_NonDirectional_index-1
							D_ND_degree_vec[current_degree].
								bidPrice_difference_Directional_D_up_end[Directional_NonDirectional_index-1] =
							D_ND_degree_vec[current_degree].
								bidPrice_difference_Directional_D_up[Directional_NonDirectional_index-1];

						}
						else if (D_ND_degree_vec[current_degree].
							bidPrice_difference_Directional_D_down[Directional_NonDirectional_index - 1] != 0)
						{
							//it is down
							//put in end array the label of Ddown of Directional_NonDirectional_index-1
							D_ND_degree_vec[current_degree].
								bidPrice_difference_Directional_D_down_end[Directional_NonDirectional_index - 1] =
							D_ND_degree_vec[current_degree].
								bidPrice_difference_Directional_D_down[Directional_NonDirectional_index - 1];
						}
						//determine if Directional_NonDirectional_index-1 is single segment to delete its direction label
						//get the start of Directional_NonDirectional_index -1 direction
							//get direction label
						D_ND_degree_vec[current_degree].
							bidPrice_difference_Directional_D_up[Directional_NonDirectional_index - 1];
							//search for start of direction label

					}
				}
			}
			//1.start			
			//this condition treat the case when price data starts with +ve up move
			if ((sgn(*it) == 1) && (Directional_NonDirectional_index == 1)) //we are in +ve up move So start Dup
			{
				D_ND_degree_vec[current_degree].bidPrice_difference_move_start_MS[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].move_start_MS);
				D_ND_degree_vec[current_degree].move_start_MS++;
				D_ND_degree_vec[current_degree].bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].move_start_MS_number_of_moves);
				D_ND_degree_vec[current_degree].bidPrice_difference_to_previous_movement_percentage_many_percentages_var = std::numeric_limits<float>::max();
				bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = D_ND_degree_vec[current_degree].bidPrice_difference_to_previous_movement_percentage_many_percentages_var;
				
				//we start Dup direction
				D_ND_degree_vec[current_degree].
				Directional_D_up = 1;
				D_ND_degree_vec[current_degree].
				Directional_D_number_moves_up = 1;
				D_ND_degree_vec[current_degree].
				bidPrice_difference_Directional_D_up[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].Directional_D_up);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_Directional_D_number_moves_up[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].Directional_D_number_moves_up);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_Directional_D_up_start[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].Directional_D_up);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_Directional_D_up_continuation[Directional_NonDirectional_index] = (0);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_Directional_D_up_end[Directional_NonDirectional_index] = (0);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_Directional_D_up_confirmation[Directional_NonDirectional_index] = (0);
				//D_ND_degree_vec[current_degree].bidPrice_difference_Directional_D_up_degree[Directional_NonDirectional_index] = (Directional_NonDirectional_Degree);

				//we start NDup direction
				D_ND_degree_vec[current_degree].
				NonDirectional_ND_up = 1;
				D_ND_degree_vec[current_degree].
				NonDirectional_ND_number_moves_up = 1;
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_up[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].NonDirectional_ND_up);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_number_moves_up[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].NonDirectional_ND_number_moves_up);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_up_start[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].NonDirectional_ND_up);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_up_continuation[Directional_NonDirectional_index] = (0);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_up_end[Directional_NonDirectional_index] = (0);
				D_ND_degree_vec[current_degree].
				bidPrice_difference_NonDirectional_ND_up_confirmation[Directional_NonDirectional_index] = (0);
				//D_ND_degree_vec[current_degree].D_ND_degree_vec[current_degree].bidPrice_difference_NonDirectional_ND_up_degree[Directional_NonDirectional_index] = (D_ND_degree_vec[current_degree].Directional_NonDirectional_Degree);
			}

			//1.start
			//this condition test change of direction to make new direction start
			if ((sgn(*it) == 1)&&(sgn(bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index])==-1|| sgn(bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index]) == 0))
			{
				//1.new direction move is larger than or = previous 3 Directional segments
				//a.get size of new direction move
				*it;
				//c.determine that previous segment is Directional
				if (is_Directional(*it, Directional_NonDirectional_index, current_degree))
				{
					//d.determine that previous segment is part of 3 segments at least
					//there might be the condition that we have 1st segment then we have 3 segments of one lesser degree which make 2nd segment So using start and end will not help
					//then we need to make new array which gives each segment a number in the move
					//note: it is already done bidPrice_difference_Directional_D_number_moves_up

					is_Single_segment(*it, Directional_NonDirectional_index, current_degree);
					is_Double_segment(*it, Directional_NonDirectional_index, current_degree);
					is_Triple_or_More_segments(*it, Directional_NonDirectional_index, current_degree);
					//b.get size of previous 3 Directional segments
				}
				else if (is_NonDirectional(*it, Directional_NonDirectional_index, current_degree))
				{

				}
				

			}

			//2.continuation
			//test if current move is continuation for previous same direction move
			if ((sgn(*it) == 1) && (Directional_NonDirectional_index != 1) && (sgn(*(it - 1)) != 1)) //we are in up move after sideway zero move or down move
			{
				//we need to test degree of it-1
				//if it is same degree as max degree>>>>>>>we need to make variable of max degree which is updated continuously to test any move against it OR we need to get previous move degree and check for start and end of this move to determine if we are in higher degree as previous move or at same degree>>>>we will calculate how many moves are present without end
				//we want to merge pricediff[index] and pricediff[index-1]
				bidPrice_difference_move_start_MS[Directional_NonDirectional_index] = bidPrice_difference_move_start_MS[Directional_NonDirectional_index - 1];
				bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index] = bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index - 1] + 1;
				//we calculate percentage for both ticklines
				bidPrice_difference_many_differences_var = bidPrice[Directional_NonDirectional_index] - bidPrice[Directional_NonDirectional_index - bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index]];
				//here we test if previous move several number of moves before, is index 0 so we have division by 0 or any other condition where previous price diff was 0
				if (bidPrice_difference[Directional_NonDirectional_index - bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index]] == 0)///this may happen with any price difference =0 ?????????
				{
					bidPrice_difference_to_previous_movement_percentage_many_percentages_var = std::numeric_limits<float>::max();
					bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = bidPrice_difference_to_previous_movement_percentage_many_percentages_var;
				}
				else if (bidPrice_difference[Directional_NonDirectional_index - bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index]] != 0)
				{
					bidPrice_difference_to_previous_movement_percentage_many_percentages_var = bidPrice_difference_many_differences_var / bidPrice_difference[Directional_NonDirectional_index - bidPrice_difference_move_start_MS_number_of_moves[Directional_NonDirectional_index]];
					bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index] = bidPrice_difference_to_previous_movement_percentage_many_percentages_var;
				}

				//now we fill arrays for ND as we consider zero move >> ND at beginning then we can test up or down according to the previous trend of which it is a segment???????????????			
				bidPrice_difference_NonDirectional_ND_up[Directional_NonDirectional_index] = (bidPrice_difference_NonDirectional_ND_up[Directional_NonDirectional_index - 1]);
				bidPrice_difference_NonDirectional_ND_number_moves_up[Directional_NonDirectional_index] = (bidPrice_difference_NonDirectional_ND_number_moves_up[Directional_NonDirectional_index - 1] + 1);
				bidPrice_difference_NonDirectional_ND_up_start[Directional_NonDirectional_index] = (0);
				bidPrice_difference_NonDirectional_ND_up_continuation[Directional_NonDirectional_index] = (bidPrice_difference_NonDirectional_ND_up[Directional_NonDirectional_index - 1]);
				bidPrice_difference_NonDirectional_ND_up_end[Directional_NonDirectional_index] = (0);
				bidPrice_difference_NonDirectional_ND_up_confirmation[Directional_NonDirectional_index] = (0);
				bidPrice_difference_NonDirectional_ND_up_degree[Directional_NonDirectional_index] = (bidPrice_difference_NonDirectional_ND_up_degree[Directional_NonDirectional_index - 1]);


				bidPrice_difference_NonDirectional_ND_down[Directional_NonDirectional_index] = (bidPrice_difference_NonDirectional_ND_down[Directional_NonDirectional_index - 1]);
				bidPrice_difference_NonDirectional_ND_number_moves_down[Directional_NonDirectional_index] = (bidPrice_difference_NonDirectional_ND_number_moves_down[Directional_NonDirectional_index - 1] + 1);
				bidPrice_difference_NonDirectional_ND_down_start[Directional_NonDirectional_index] = (0);
				bidPrice_difference_NonDirectional_ND_down_continuation[Directional_NonDirectional_index] = (bidPrice_difference_NonDirectional_ND_down[Directional_NonDirectional_index - 1]);
				bidPrice_difference_NonDirectional_ND_down_end[Directional_NonDirectional_index] = (0);
				bidPrice_difference_NonDirectional_ND_down_confirmation[Directional_NonDirectional_index] = (0);
				bidPrice_difference_NonDirectional_ND_down_degree[Directional_NonDirectional_index] = (bidPrice_difference_NonDirectional_ND_down_degree[Directional_NonDirectional_index - 1]);

			}
			//confirmation
			//we want to confirm either up or down direction of previous first move zero side way at beginning of data
			if ((sgn(*it) != 0) && (Directional_NonDirectional_index != 0) && (sgn(*(it - 1)) == 0))//>>>>>>>3
			{
				//if sign is +ve we keep previous NDup else we keep NDdown
				if ((sgn(*it) == 1)) //work on down move making it zerod
				{
					//find degree of previous move
					Directional_NonDirectional_Degree = (bidPrice_difference_NonDirectional_ND_up_degree[Directional_NonDirectional_index - 1]);
					//loop in degree till current degree
					for (Directional_NonDirectional_Degree_loop_index = Directional_NonDirectional_Degree; ; ++Directional_NonDirectional_Degree_loop_index)
					{
						//find label number of previous move
						Directional_NonDirectional_Label_number = bidPrice_difference_NonDirectional_ND_up[Directional_NonDirectional_index - 1];
						//find start of previous move
						for (std::vector<int>::iterator it = bidPrice_difference_NonDirectional_ND_up_start.begin() + Directional_NonDirectional_index; it != bidPrice_difference_NonDirectional_ND_up_start.begin(); --it)

						{
							if ((*it != Directional_NonDirectional_Label_number))//( bidPrice_difference_NonDirectional_ND_up_degree[it - bidPrice_difference_NonDirectional_ND_up_start.begin()]== Directional_NonDirectional_Degree))
							{
								continue;
							}
							else if ((*it == Directional_NonDirectional_Label_number) && (bidPrice_difference_NonDirectional_ND_up_degree[it - bidPrice_difference_NonDirectional_ND_up_start.begin()] == Directional_NonDirectional_Degree))

							{
								bidPrice_difference_NonDirectional_ND_up_start_index = it - bidPrice_difference_NonDirectional_ND_up_start.begin();
								break;
							}
						}
						//find end of previous move
						for (std::vector<int>::iterator it = bidPrice_difference_NonDirectional_ND_up_end.begin() + Directional_NonDirectional_index; it != bidPrice_difference_NonDirectional_ND_up_end.begin(); --it)

						{
							if (*it != Directional_NonDirectional_Label_number)
							{
								if ((bidPrice_difference_NonDirectional_ND_up_start[it - bidPrice_difference_NonDirectional_ND_up_start.begin()] > bidPrice_difference_NonDirectional_ND_up_start_index))
								{
									continue;
								}

							}
							else if (*it != Directional_NonDirectional_Label_number)
							{
								if ((bidPrice_difference_NonDirectional_ND_up_start[it - bidPrice_difference_NonDirectional_ND_up_start.begin()] == bidPrice_difference_NonDirectional_ND_up_start_index))
								{
									//no end for this Directional_NonDirectional_Label_number,so make test end to it
									bidPrice_difference_NonDirectional_ND_up_end[(it - 1) - bidPrice_difference_NonDirectional_ND_up_end.begin()] == bidPrice_difference_NonDirectional_ND_up_start_index;

									//zero NDdown from begin of NDup start to current -1
									for (std::vector<int>::iterator it = bidPrice_difference_NonDirectional_ND_up_start.begin() + bidPrice_difference_NonDirectional_ND_up_start_index; it < bidPrice_difference_NonDirectional_ND_up_start.begin() + Directional_NonDirectional_index; it++)
									{
										int index2 = it - bidPrice_difference_NonDirectional_ND_up_start.begin();
										bidPrice_difference_NonDirectional_ND_down[index2] = 0;
										bidPrice_difference_NonDirectional_ND_number_moves_down[index2] = 0;
										bidPrice_difference_NonDirectional_ND_down_start[index2] = (0);
										bidPrice_difference_NonDirectional_ND_down_continuation[index2] = 0;
										bidPrice_difference_NonDirectional_ND_down_end[index2] = (0);
										bidPrice_difference_NonDirectional_ND_down_confirmation[index2] = (0);
										bidPrice_difference_NonDirectional_ND_down_degree[index2] = 0;

									}
									goto cnt;
								}

							}
							else if ((*it == Directional_NonDirectional_Label_number) && (bidPrice_difference_NonDirectional_ND_up_degree[it - bidPrice_difference_NonDirectional_ND_up_end.begin()] == Directional_NonDirectional_Degree))
							{
								bidPrice_difference_NonDirectional_ND_up_end_index = it - bidPrice_difference_NonDirectional_ND_up_end.begin();
								break;
							}
						}
						//if it has end then find start of higher degree by one
						//loop to find end
						//if it has no end then end the NDup and zero the NDdown
					cnt:
					}
				}
				else if ((sgn(*it) == -1))
				{
					//find degree of previous move
					Directional_NonDirectional_Degree = (bidPrice_difference_NonDirectional_ND_down_degree[Directional_NonDirectional_index - 1]);
					//loop in degree till current degree
					for (Directional_NonDirectional_Degree_loop_index = Directional_NonDirectional_Degree; ; ++Directional_NonDirectional_Degree_loop_index)
					{
						//find label number of previous move
						Directional_NonDirectional_Label_number = bidPrice_difference_NonDirectional_ND_down[Directional_NonDirectional_index - 1];
						//find start of previous move
						for (std::vector<int>::iterator it = bidPrice_difference_NonDirectional_ND_down_start.begin() + Directional_NonDirectional_index; it != bidPrice_difference_NonDirectional_ND_down_start.begin(); --it)

						{
							if ((*it != Directional_NonDirectional_Label_number))//( bidPrice_difference_NonDirectional_ND_down_degree[it - bidPrice_difference_NonDirectional_ND_down_start.begin()]== Directional_NonDirectional_Degree))
							{
								continue;
							}
							else if ((*it == Directional_NonDirectional_Label_number) && (bidPrice_difference_NonDirectional_ND_down_degree[it - bidPrice_difference_NonDirectional_ND_down_start.begin()] == Directional_NonDirectional_Degree))

							{
								bidPrice_difference_NonDirectional_ND_down_start_index = it - bidPrice_difference_NonDirectional_ND_down_start.begin();
								break;
							}
						}
						//find end of previous move
						for (std::vector<int>::iterator it = bidPrice_difference_NonDirectional_ND_down_end.begin() + Directional_NonDirectional_index; it != bidPrice_difference_NonDirectional_ND_down_end.begin(); --it)

						{
							if (*it != Directional_NonDirectional_Label_number)
							{
								if ((bidPrice_difference_NonDirectional_ND_down_start[it - bidPrice_difference_NonDirectional_ND_down_start.begin()] > bidPrice_difference_NonDirectional_ND_down_start_index))
								{
									continue;
								}

							}
							else if (*it != Directional_NonDirectional_Label_number)
							{
								if ((bidPrice_difference_NonDirectional_ND_down_start[it - bidPrice_difference_NonDirectional_ND_down_start.begin()] == bidPrice_difference_NonDirectional_ND_down_start_index))
								{
									//no end for this Directional_NonDirectional_Label_number,so make test end to it
									bidPrice_difference_NonDirectional_ND_down_end[(it - 1) - bidPrice_difference_NonDirectional_ND_down_end.begin()] == bidPrice_difference_NonDirectional_ND_down_start_index;

									//zero NDup from begin of NDdown start to current -1
									for (std::vector<int>::iterator it = bidPrice_difference_NonDirectional_ND_down_start.begin() + bidPrice_difference_NonDirectional_ND_down_start_index; it < bidPrice_difference_NonDirectional_ND_down_start.begin() + Directional_NonDirectional_index; it++)
									{
										int index2 = it - bidPrice_difference_NonDirectional_ND_down_start.begin();
										bidPrice_difference_NonDirectional_ND_up[index2] = 0;
										bidPrice_difference_NonDirectional_ND_number_moves_up[index2] = 0;
										bidPrice_difference_NonDirectional_ND_up_start[index2] = (0);
										bidPrice_difference_NonDirectional_ND_up_continuation[index2] = 0;
										bidPrice_difference_NonDirectional_ND_up_end[index2] = (0);
										bidPrice_difference_NonDirectional_ND_up_confirmation[index2] = (0);
										bidPrice_difference_NonDirectional_ND_up_degree[index2] = 0;

									}
									goto cnt;
								}

							}
							else if ((*it == Directional_NonDirectional_Label_number) && (bidPrice_difference_NonDirectional_ND_down_degree[it - bidPrice_difference_NonDirectional_ND_down_end.begin()] == Directional_NonDirectional_Degree))
							{
								bidPrice_difference_NonDirectional_ND_down_end_index = it - bidPrice_difference_NonDirectional_ND_down_end.begin();
								break;
							}
						}
						//if it has end then find start of higher degree by one
						//loop to find end
						//if it has no end then end the NDup and zero the NDdown
					cnt:
					}
				}
			}
			//first we need to get previous move degree
			//int bidPrice_difference_NonDirectional_ND_up_degree_var;
			//end
		}

		if ((sgn(*it) == 1) && (Directional_NonDirectional_index == 1))//we start  data with +ve up move
		{

			//here we test if we are in 2nd element of array which represents first tickline"price difference" ever
			if ((bidPrice_difference_Directional_D_up[Directional_NonDirectional_index-1]==0)&&(bidPrice_difference_move_start_MS[Directional_NonDirectional_index]==1)) //begin is up tickline
			{
				Directional_NonDirectional_Degree = 0;

				//here we consider first tickline Directional
				Directional_D_up = 1;
				Directional_D_number_moves_up = 1;
				bidPrice_difference_Directional_D_up[Directional_NonDirectional_index] =(Directional_D_up);
				bidPrice_difference_Directional_D_number_moves_up[Directional_NonDirectional_index] =(Directional_D_number_moves_up);
				bidPrice_difference_Directional_D_up_start[Directional_NonDirectional_index] =(Directional_D_up);		
				//bidPrice_difference_Directional_D_up_continuation[Directional_NonDirectional_index] =(0);
				//bidPrice_difference_Directional_D_up_end[Directional_NonDirectional_index] =(0);
				//bidPrice_difference_Directional_D_up_confirmation[Directional_NonDirectional_index] =(0);
				bidPrice_difference_Directional_D_up_degree[Directional_NonDirectional_index] =(Directional_NonDirectional_Degree);

				//here we consider first tickline NonDirectional
				NonDirectional_ND_up = 1;
				NonDirectional_ND_number_moves_up = 1;
				bidPrice_difference_NonDirectional_ND_up[Directional_NonDirectional_index] =(NonDirectional_ND_up);
				bidPrice_difference_NonDirectional_ND_number_moves_up[Directional_NonDirectional_index] =(NonDirectional_ND_number_moves_up);
				bidPrice_difference_NonDirectional_ND_up_start[Directional_NonDirectional_index] =(NonDirectional_ND_up);
				//bidPrice_difference_NonDirectional_ND_up_continuation[Directional_NonDirectional_index] =(0);
				//bidPrice_difference_NonDirectional_ND_up_end[Directional_NonDirectional_index] =(0);
				//bidPrice_difference_NonDirectional_ND_up_confirmation[Directional_NonDirectional_index] =(0);
				bidPrice_difference_NonDirectional_ND_up_degree[Directional_NonDirectional_index] =(Directional_NonDirectional_Degree);

			}
			//HERE we have error if starting tickline =0 price difference or 2nd tickline is =0???????????????
			else if (((bidPrice_difference_Directional_D_down[Directional_NonDirectional_index - 1] == 1) || (bidPrice_difference_NonDirectional_ND_down[Directional_NonDirectional_index - 1] == 1)) && (bidPrice_difference_move_start_MS[Directional_NonDirectional_index] == 2)) //begin is down tickline and we are now in 2nd up tickline
			{
				Directional_D_up = 1;
				Directional_D_number_moves_up = 1;
				Directional_NonDirectional_Degree = 0;
				bidPrice_difference_Directional_D_up[Directional_NonDirectional_index] =(Directional_D_up);
				bidPrice_difference_Directional_D_number_moves_up[Directional_NonDirectional_index] =(Directional_D_number_moves_up);
				bidPrice_difference_Directional_D_up_start[Directional_NonDirectional_index] =(Directional_D_up);
				//bidPrice_difference_Directional_D_up_continuation[Directional_NonDirectional_index] =(0);
				//bidPrice_difference_Directional_D_up_end[Directional_NonDirectional_index] =(0);
				//bidPrice_difference_Directional_D_up_confirmation[Directional_NonDirectional_index] =(0);
				bidPrice_difference_Directional_D_up_degree[Directional_NonDirectional_index] =(Directional_NonDirectional_Degree);
			}

			if (abs(bidPrice_difference_to_previous_movement_percentage[Directional_NonDirectional_index]))
			{

			}
		}

	}

	
	
	bidPrice_difference_Directional_D.push_back( Directional_D);
	Directional_D++;
	bidPrice_difference_Directional_D_number_moves.push_back(Directional_D_number_moves);

	bidPrice_difference_NonDirectional_ND.push_back(NonDirectional_ND);
	NonDirectional_ND++;
	bidPrice_difference_NonDirectional_ND_number_moves.push_back(NonDirectional_ND_number_moves);

	for (std::vector<float>::iterator it = bidPrice_difference_to_previous_movement_percentage.begin()+2; it != bidPrice_difference_to_previous_movement_percentage.end(); ++it)
	{		
		//check sign of current price difference against previous price difference
		//normally bidPrice_difference_to_previous_movement_percentage must be negative because either of price difference is in counter direction to other
		if (sgn(*it) == -1)
		{
			//I want to check first retracement in movement
			{
				if ((*it) < 61.8)
				{
					bidPrice_difference_move_start_MS.push_back(move_start_MS);
					move_start_MS++;
					bidPrice_difference_move_start_MS_number_of_moves.push_back(move_start_MS_number_of_moves);

					bidPrice_difference_Directional_D.push_back(Directional_D);
					Directional_D++;

				}
				else if (((*it) > 61.8) && ((*it) < 100))
				{
					bidPrice_difference_move_start_MS.push_back(move_start_MS);
					move_start_MS++;
					bidPrice_difference_move_start_MS_number_of_moves.push_back(move_start_MS_number_of_moves);

					bidPrice_difference_NonDirectional_ND.push_back(NonDirectional_ND);
					NonDirectional_ND++;

				}
			}
		}
		//bidPrice_difference_to_previous_movement_percentage is positive when both price differences is in same direction
		else if (sgn(*it) == 1)
		{
			bidPrice_difference_move_start_MS.push_back(*std::prev(it));
			//move_start_MS++;

			bidPrice_difference_Directional_D.push_back(*std::prev(it));
			//Directional_D++;

			//now I must recalculate  bidPrice_difference_to_previous_movement_percentage of current and previous elements
			//first I get the index of current iterator
			size_t i = std::distance(bidPrice_difference_to_previous_movement_percentage.begin(), it);
			//then I calculate number of moves till current move inclused
			int MS_number_of_moves_tillnow = bidPrice_difference_move_start_MS_number_of_moves[i - 1] + 1;
			bidPrice_difference_move_start_MS_number_of_moves[i] = MS_number_of_moves_tillnow;

			int total_bidPrice_difference = 0;
			for (int x = 0; x < MS_number_of_moves_tillnow; x++)
			{
				//bidPrice_difference_to_previous_movement_percentage[i - MS_number_of_moves_tillnow] =
				total_bidPrice_difference = total_bidPrice_difference + bidPrice_difference[i - x];
				/// bidPrice_difference[i - 2]) * 100);
			}
			for (int x = 0; x < MS_number_of_moves_tillnow; x++)
			{
				bidPrice_difference_to_previous_movement_percentage[i - x] = (((total_bidPrice_difference) / bidPrice_difference[i - MS_number_of_moves_tillnow ]) * 100);
				
			}
			it--;
		}
	}
	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;


}