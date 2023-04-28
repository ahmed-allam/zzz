#ifndef CSV_TIME_BID_ASK_DIFFERENCE
#define CSV_TIME_BID_ASK_DIFFERENCE

#include "csv_to_monowave_vectors.h"

#include <numeric> //for std::adjacent_difference
//#include <chrono> //for timing cpu >>>not supported in vs2010
#include <boost/chrono.hpp>
//18-12-2021
#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

//21-12-2021
//#include "../Worker.h"
class Worker;
class csv_time_bid_ask_difference : public csv_to_monowave_vectors
{
public:
	csv_time_bid_ask_difference();
	csv_time_bid_ask_difference(Worker*);

	
//private:
	//csv_time_bid_ask_difference() = delete;
public:
	void get_epochpartTime_difference();
	void get_tickpartTime_difference();
	void get_bidPrice_difference();
	void get_bidPrice_difference_absolute();
	void get_askPrice_difference();
	void get_askPrice_difference_absolute();
	void get_number_Units_Eachpoint_Xaxis();

public:
	//members for csv_time_bid_ask_difference
	// Declare intermediate output storage
	std::vector<int> epochpartTime_difference;
	std::vector<int> tickpartTime_difference;

	//18-12-2021 vector to store number of units of each point on x axis
	std::vector<int> number_Units_Eachpoint_Xaxis;
	std::vector<int> amount_Time_between_2Tikcs_with_OffTime;
	std::vector<int> amount_Time_between_2Tikcs_without_OffTime;
	std::vector<int> amount_Time_between_2Tikcs_with_OffTime_summed;
	std::vector<int> amount_Time_between_2Tikcs_without_OffTime_summed;

	int Weekly_Holidays_Time, Vacancy_Festival_Holidays, daily_closure_to_open_Time, daily_BreakingTime, Emergency_OffTime, TotalOffTime;

	int openingTimeHour, closingTimeHour, breakTimeStartHour, breakTimeEndHour;
	int openingTimeMinute, closingTimeMinute, breakTimeStartMinute, breakTimeEndMinute;

	std::vector<int> bidPrice_difference;
	std::vector<int> bidPrice_difference_absolute;

	std::vector<int> askPrice_difference;
	std::vector<int> askPrice_difference_absolute;

public:
	boost::chrono::steady_clock::time_point start, stop;
	boost::chrono::microseconds duration ;
};
#endif //CSV_TIME_BID_ASK_DIFFERENCE