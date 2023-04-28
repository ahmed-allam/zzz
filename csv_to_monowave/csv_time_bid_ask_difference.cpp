#include "csv_time_bid_ask_difference.h"
#include "../Worker.h"

/////////////////////////////////////////////////////////////////////////////
float absolute_price_difference (float x, float y) {return abs(x-y);}
/////////////////////////////////////////////////////////////////////////////
using namespace boost::chrono ;

void csv_time_bid_ask_difference::get_epochpartTime_difference()
{
	//we get epoch difference to detect holidays
	start = high_resolution_clock::now();
	epochpartTime_difference.resize(epochpartTime.size());
	std::adjacent_difference(epochpartTime.begin(), epochpartTime.end(), epochpartTime_difference.begin());
	epochpartTime_difference[0] = 0;

	// After function call 
	stop = high_resolution_clock::now();
	// Subtract stop and start timepoints and cast it to required unit. Predefined units are nanoseconds, microseconds, milliseconds, seconds, minutes, hours. Use duration_cast() function. 
	duration = duration_cast<microseconds>(stop - start);
	// To get the value of duration use the count() member function on the duration object 
	std::cout << duration.count() << std::endl;

}
void csv_time_bid_ask_difference::get_tickpartTime_difference()
{
	//we get tickpartTime difference 
	start = high_resolution_clock::now();
	tickpartTime_difference.resize(tickpartTime.size());
	//we will need to use for loop to compare with values of epochpartTime
	for (std::vector<unsigned int>::size_type i = 0; i < tickpartTime.size(); i++)
	{
		if (i > 0)
		{
			//epochpartTime changes every hour by 3600 sec or 3600000 millisec
			if ((epochpartTime_difference[i]) == 3600)
			{
				//we are in next hour
				tickpartTime_difference[i] = ((tickpartTime[i]) + (1000 * 60 * 60)) - (tickpartTime[i - 1]);
			}
			//else if(epochpartTime_difference[i] <= (day_seconds))
			else if (epochpartTime_difference[i] == 0)
			{
				//we are in the same hour
				tickpartTime_difference[i] = ((tickpartTime[i])) - (tickpartTime[i - 1]);
			}
			//18-12-2021 I ll change condition to > 3600
			//else if (epochpartTime_difference[i] >= (3600*49))
			else if (epochpartTime_difference[i] > (3600))

			{
				//we are in an hour after the next hour:may be Weekly_Holidays_Time ,	daily_closure_to_open_Time,	daily_BreakingTime ,Emergency_OffTime,vacancy or festival holidays
				tickpartTime_difference[i] = ((tickpartTime[i]) + (1000 * 60 * 60)) - (tickpartTime[i - 1]);
			}
			//here we should check for holidays"official ones are 25th december and 1st january" 
		}
		else if (i == 0)
		{
			//tickpartTime_difference[i]=((tickpartTime[i]));
			tickpartTime_difference[i] = 0;//this because we calculate difference from last price action time not the beginning of hour
		}
	}

	//std::adjacent_difference(tickpartTime.begin(), tickpartTime.end(), tickpartTime_difference.begin());
	//epochpartTime_difference[0]=0; ////the first difference is calculated from beginning of hour so the first tickpartTime is the increase in time from zero beginning of hour

	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;

}
void csv_time_bid_ask_difference::get_bidPrice_difference()
{
	//calculate bidPrice difference
	start = high_resolution_clock::now();
	bidPrice_difference.resize(bidPrice.size());
	std::adjacent_difference(bidPrice.begin(), bidPrice.end(), bidPrice_difference.begin());
	bidPrice_difference[0] = 0;
	//convert difference to absolute difference

	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;

}
void csv_time_bid_ask_difference::get_bidPrice_difference_absolute()
{
	//caluculate bidPrice difference with absolute value
	start = high_resolution_clock::now();
	bidPrice_difference_absolute.resize(bidPrice.size());
	std::adjacent_difference(bidPrice.begin(), bidPrice.end(), bidPrice_difference_absolute.begin(), absolute_price_difference);
	bidPrice_difference_absolute[0] = 0;
	//convert difference to absolute difference

	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;

}
void csv_time_bid_ask_difference::get_askPrice_difference()
{
	start = high_resolution_clock::now();
	askPrice_difference.resize(askPrice.size());
	std::adjacent_difference(askPrice.begin(), askPrice.end(), askPrice_difference.begin());
	askPrice_difference[0] = 0;
	//convert difference to absolute difference

	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;

}
void csv_time_bid_ask_difference::get_askPrice_difference_absolute()
{
	//caluculate bidPrice difference with absolute value
	start = high_resolution_clock::now();
	askPrice_difference_absolute.resize(askPrice.size());
	std::adjacent_difference(askPrice.begin(), askPrice.end(), askPrice_difference_absolute.begin(), absolute_price_difference);
	askPrice_difference_absolute[0] = 0;
	//convert difference to absolute difference

	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
}
void csv_time_bid_ask_difference::get_number_Units_Eachpoint_Xaxis()
{
	//18-12-2021 now we will calculate number of units of x axis at each point	
	start = high_resolution_clock::now();

	number_Units_Eachpoint_Xaxis.resize(tickpartTime.size());
	amount_Time_between_2Tikcs_with_OffTime.resize(tickpartTime.size());
	amount_Time_between_2Tikcs_without_OffTime.resize(tickpartTime.size());
	amount_Time_between_2Tikcs_with_OffTime_summed.resize(tickpartTime.size());
	amount_Time_between_2Tikcs_without_OffTime_summed.resize(tickpartTime.size());

	Weekly_Holidays_Time = 0;
	Vacancy_Festival_Holidays = 0;
	daily_closure_to_open_Time = 0;
	daily_BreakingTime = 0;
	Emergency_OffTime = 0;
	TotalOffTime = 0;

	//we will need to use for loop to compare with values of epochpartTime
	for (std::vector<unsigned int>::size_type i = 0; i < tickpartTime.size(); i++)
	{
		if (i > 0)
		{
			//number of milliseconds between 2 ticks = (epochpartTime_difference *1000)+tickpartTime_difference "- (holidays between 2 ticks) in case we draw chart without holidays"
			//epochpartTime changes every hour by 3600 sec or 3600000 millisec
			//if epochpartTime_difference is greater than 3600 then we are after one hour 
			//18-12-2021
			//if epochpartTime_difference = 0 we are in same hour
			//if epochpartTime_difference =3600 * 1 ,we are in next hour in same day
			//if epochpartTime_difference =3600 * 24,we are in next day
			//if epochpartTime_difference =3600 * 48,we are in next 2 days
			//we want to make x axis as time scale with ability to either keep holiday times as part of scale which might lead to big parts of chart with no action as these parts are days of Holidays especially on less than day "ticks 5 min hourly 6 hours charts" 
			//Or we remove Holidays totally from x axis scale by calculating their time"Holidays milliseconds duration" and subtracting Holidays times from tick to tick time ,then converting remaining time to time units .Afterwards we will convert these time units to pixels with 1 to 1 or 2 to 1 scale
			//what do we do if we have part of time without trading???
			// 
			//we will first make sure that epochpartTime is not after holiday
			//we will divide holidays into weekly,daily closure to open times,	Vacancy_Festival_Holidays ,anonymous which may have resulted from world wide market closure due to emergency
			/*
			time_t btime_ = epochpartTime[i]; //This is epoch time read from epochpartTime vector
			//std::wstring epochpartTimeDatestring_ = L"";
			boost::gregorian::date const epochpartTime_Date_ = boost::posix_time::from_time_t(btime_).date();
			boost::posix_time::ptime const epochpartTime_Time_ = boost::posix_time::from_time_t(btime_);

			//std::string year_ = boost::lexical_cast<std::string>	(epochpartTime_Date_.year());
			//std::string day_ = boost::lexical_cast<std::string>	(epochpartTime_Date_.day());
			std::string dayofweek_ = boost::lexical_cast<std::string>	(epochpartTime_Date_.day_of_week());
			std::cout << dayofweek_ << std::endl;
			//qDebug(dayofweek_.c_str());
			int hours_ =	epochpartTime_Time_.time_of_day().hours();
			int minutes_ =	epochpartTime_Time_.time_of_day().minutes();
			*/
			/*
			time_t btime_ = 1505790902; //This is epoch time read from "/proc/stat" file.
			std::wstring currentDate_ = L"";
			boost::gregorian::date current_date_ =
					 boost::posix_time::from_time_t(btime_).date();

			std::wstring year_ = boost::lexical_cast<std::wstring>
												 (current_date_.year());
			std::wstring day_ = boost::lexical_cast<std::wstring>
												 (current_date_.day());
			*/
			//if ((epochpartTime_difference[i]) == 3600)
			if (((epochpartTime_difference[i]) / 3600) > 0)
			{
				time_t btime_current = epochpartTime[i]; //This is epoch time read from epochpartTime vector
				time_t btime_previous = epochpartTime[i - 1]; //This is epoch time read from epochpartTime vector
				boost::gregorian::date const epochpartTime_Date_current = boost::posix_time::from_time_t(btime_current).date();
				boost::gregorian::date const epochpartTime_Date_previous = boost::posix_time::from_time_t(btime_previous).date();
				boost::posix_time::ptime const epochpartTime_Time_current = boost::posix_time::from_time_t(btime_current);
				boost::posix_time::ptime const epochpartTime_Time_previous = boost::posix_time::from_time_t(btime_previous);
				//if date is same as date of previous tick ,then we are in same day
				if (epochpartTime_Date_current == epochpartTime_Date_previous)
				{
					//we are in same day so it is not weekly holidays or daily off hours >>>No this needs modification as some instruments have mid day breaking time
					// if (breakingTime==true)
						//if  (epochpartTime_Date_current = breakingHour+3600 And DST==winter)
						// Or  (epochpartTime_Date_current + 3600 = breakingHour+3600+3600 And DST==summer)
						// {
						//		here breakingHour+3600 represents single hour break
						//		in case break is larger than 1 hour we modify 3600
						//		tickpartTime_difference[i] = ((tickpartTime[i]) + ((1000 * 60 * 60)*	((epochpartTime_difference[i]) / 3600))) - (tickpartTime[i - 1]);

						//		Weekly_Holidays_Time = 0;
						//		daily_closure_to_open_Time = 0;
						//		daily_BreakingTime=3600????
						//		Emergency_OffTime = 0;
						//		TotalOffTime =Weekly_Holidays_Time +daily_closure_to_open_Time+daily_BreakingTime+Emergency_OffTime;

						//		amount_Time_between_2Tikcs_with_OffTime[i] = tickpartTime_difference[i];
						//		amount_Time_between_2Tikcs_without_OffTime[i] = tickpartTime_difference[i]) - TotalOffTime;
						// amount_Time_between_2Tikcs_with_OffTime_summed[i]= amount_Time_between_2Tikcs_with_OffTime_summed[i-1] + amount_Time_between_2Tikcs_with_OffTime[i];
					//amount_Time_between_2Tikcs_without_OffTime_summed[i] = amount_Time_between_2Tikcs_without_OffTime_summed[i - 1] + amount_Time_between_2Tikcs_without_OffTime[i];
						// }
						// 
					// As for now ,forex does not have breaking time so we will continue 
					//So if we are in next hour ,then we should test if tick is so slow that offtime may have occured 
					// how to test if tick is too slow so that offtime may have occured????? I will not consider emergency off time unless documented by authorities and then I will edit the program my self
					// if not so slow ,then we should calculate offtime variables and amount of time between the two ticks
					//if epochpartTime_difference =3600 * 1 ,we are in next hour in same day
					//tickpartTime_difference[i] = ((tickpartTime[i]) + (1000 * 60 * 60)) - (tickpartTime[i - 1]);
					tickpartTime_difference[i] = ((tickpartTime[i]) + ((1000 * 60 * 60) * ((epochpartTime_difference[i]) / 3600))) - (tickpartTime[i - 1]);

					Weekly_Holidays_Time = 0;
					Vacancy_Festival_Holidays = 0;
					daily_closure_to_open_Time = 0;
					daily_BreakingTime = 0;
					Emergency_OffTime = 0;
					//TotalOffTime = ((Weekly_Holidays_Time +Vacancy_Festival_Holidays 	+ daily_closure_to_open_Time) + (daily_BreakingTime + Emergency_OffTime));
					TotalOffTime = ((Weekly_Holidays_Time + Vacancy_Festival_Holidays + daily_closure_to_open_Time) + (daily_BreakingTime + Emergency_OffTime));
					amount_Time_between_2Tikcs_with_OffTime[i] = tickpartTime_difference[i];
					amount_Time_between_2Tikcs_without_OffTime[i] = tickpartTime_difference[i] - TotalOffTime;
					amount_Time_between_2Tikcs_with_OffTime_summed[i] = amount_Time_between_2Tikcs_with_OffTime_summed[i - 1] + amount_Time_between_2Tikcs_with_OffTime[i];
					amount_Time_between_2Tikcs_without_OffTime_summed[i] = amount_Time_between_2Tikcs_without_OffTime_summed[i - 1] + amount_Time_between_2Tikcs_without_OffTime[i];
					//But is there emergency off time???or 
				}

				//if date is different than date of previous tick ,then we are in different day
				else if (epochpartTime_Date_current != epochpartTime_Date_previous)
				{
					//if epochpartTime_difference[i]/3600 == 24 ,then we are in a day after one day off
					//if epochpartTime_difference[i]/3600 == 48 ,then we are in a day after two days off. So we need to check for weekly holiday
						//if date.dayofweek == Sun ,then we are in begining of workdays after weekly holidays
					if (epochpartTime_Date_current.day_of_week().as_short_string() == "Sun")
					{
						tickpartTime_difference[i] = ((tickpartTime[i]) + ((1000 * 60 * 60) * ((epochpartTime_difference[i]) / 3600))) - (tickpartTime[i - 1]);

						Weekly_Holidays_Time = (1000 * 60 * 60) * ((epochpartTime_difference[i]) / 3600);
						//if there was 	Vacancy_Festival_Holidays starting before Weekly_Holidays_Time then we subtract 	Vacancy_Festival_Holidays - Weekly_Holidays_Time
						//Vacancy_Festival_Holidays = abs(Vacancy_Festival_Holidays - Weekly_Holidays_Time);
						daily_closure_to_open_Time = 0;
						daily_BreakingTime = 0;
						Emergency_OffTime = 0;
						TotalOffTime = Weekly_Holidays_Time + Vacancy_Festival_Holidays +		daily_closure_to_open_Time + daily_BreakingTime + Emergency_OffTime;

						amount_Time_between_2Tikcs_with_OffTime[i] = tickpartTime_difference[i];
						amount_Time_between_2Tikcs_without_OffTime[i] = tickpartTime_difference[i] - TotalOffTime;
						amount_Time_between_2Tikcs_with_OffTime_summed[i] = amount_Time_between_2Tikcs_with_OffTime_summed[i - 1] + amount_Time_between_2Tikcs_with_OffTime[i];
						amount_Time_between_2Tikcs_without_OffTime_summed[i] = amount_Time_between_2Tikcs_without_OffTime_summed[i - 1] + amount_Time_between_2Tikcs_without_OffTime[i];
					}
					//if date.dayofweek != Sun ,then we are in begining of workday after either previous work day Or daily closure to open time Or feast or emergency holidays
					else if (epochpartTime_Date_current.day_of_week().as_short_string() != "Sun")
					{
						if ((((epochpartTime_difference[i]) / 3600) > 0) && (((epochpartTime_difference[i]) / 3600) < 2))
						{
							//we are in 1st hour of working day after last hour of previous working day,forex works 24 hours continuously
							tickpartTime_difference[i] = ((tickpartTime[i]) + ((1000 * 60 * 60) * ((epochpartTime_difference[i]) / 3600))) - (tickpartTime[i - 1]);

							Weekly_Holidays_Time = 0;
							Vacancy_Festival_Holidays = 0;
							daily_closure_to_open_Time = 0;
							daily_BreakingTime = 0;
							Emergency_OffTime = 0;
							TotalOffTime = Weekly_Holidays_Time+ Vacancy_Festival_Holidays	+ daily_closure_to_open_Time + daily_BreakingTime + Emergency_OffTime;

							amount_Time_between_2Tikcs_with_OffTime[i] = tickpartTime_difference[i];
							amount_Time_between_2Tikcs_without_OffTime[i] = tickpartTime_difference[i] - TotalOffTime;
							amount_Time_between_2Tikcs_with_OffTime_summed[i] = amount_Time_between_2Tikcs_with_OffTime_summed[i - 1] + amount_Time_between_2Tikcs_with_OffTime[i];
							amount_Time_between_2Tikcs_without_OffTime_summed[i] = amount_Time_between_2Tikcs_without_OffTime_summed[i - 1] + amount_Time_between_2Tikcs_without_OffTime[i];
						}
						else if ((((epochpartTime_difference[i]) / 3600) > 1)) //&& (((epochpartTime_difference[i]) / 3600) < 2))
						{
							//we have more than one hour off time.This may be due to slow action of market,Or daily closure till open time in some instruments Or even emergency offtime	or Vacancy_Festival_Holidays 

							//it is not due to breaking time as breaking time happens in the same day
							//if daily closure till open== true
							//{
							//	if (epochpartTime_Time_current.hours().as_short_string() == daily_Open_Hour)
							//	{
							//		tickpartTime_difference[i] = ((tickpartTime[i]) + ((1000 * 60 * 60) * ((epochpartTime_difference[i]) / 3600))) - (tickpartTime[i - 1]);

							//Weekly_Holidays_Time = 0;
							//daily_closure_to_open_Time = tickpartTime_difference[i];
							//daily_BreakingTime = 0;
							//Emergency_OffTime = 0;
							//TotalOffTime = Weekly_Holidays_Time + daily_closure_to_open_Time + daily_BreakingTime + Emergency_OffTime;

							//amount_Time_between_2Tikcs_with_OffTime[i] = tickpartTime_difference[i];
							//amount_Time_between_2Tikcs_without_OffTime[i] = tickpartTime_difference[i] - TotalOffTime;
							// amount_Time_between_2Tikcs_with_OffTime_summed[i]= amount_Time_between_2Tikcs_with_OffTime_summed[i-1] + amount_Time_between_2Tikcs_with_OffTime[i];
							//amount_Time_between_2Tikcs_without_OffTime_summed[i] = //amount_Time_between_2Tikcs_without_OffTime_summed[i - 1] + //amount_Time_between_2Tikcs_without_OffTime[i];
							//	}

							//}
						}
						//else if ((((epochpartTime_difference[i]) / 3600) > 1))
						//{

						//}
					}
				}








			}
			//else if(epochpartTime_difference[i] <= (day_seconds))
			else if (epochpartTime_difference[i] == 0)
			{
				//if epochpartTime_difference = 0 we are in same hour
				tickpartTime_difference[i] = ((tickpartTime[i])) - (tickpartTime[i - 1]);
				//because we are in same hours So
				Weekly_Holidays_Time = 0;
				Vacancy_Festival_Holidays = 0;
				daily_closure_to_open_Time = 0;
				daily_BreakingTime = 0;
				Emergency_OffTime = 0;
				TotalOffTime = 0;

				amount_Time_between_2Tikcs_with_OffTime[i] = (epochpartTime_difference[i] * 1000) + tickpartTime_difference[i];
				amount_Time_between_2Tikcs_without_OffTime[i] = ((epochpartTime_difference[i] * 1000) + tickpartTime_difference[i]) - TotalOffTime;
				amount_Time_between_2Tikcs_with_OffTime_summed[i] = amount_Time_between_2Tikcs_with_OffTime_summed[i - 1] + amount_Time_between_2Tikcs_with_OffTime[i];
				amount_Time_between_2Tikcs_without_OffTime_summed[i] = amount_Time_between_2Tikcs_without_OffTime_summed[i - 1] + amount_Time_between_2Tikcs_without_OffTime[i];

				//number_Units_Eachpoint_Xaxis[i] = 0;//this because 1st point on x axis will be plotted as it is without reference to previous time,it is the begining point


			}
			//if tick time difference is greater than one hour look for weekends
			//18-12-2021 I ll change condition to > 3600
			//else if (epochpartTime_difference[i] >= (3600*49))
			//else if (epochpartTime_difference[i] > (3600))

			//{
				//tickpartTime_difference[i] = ((tickpartTime[i]) + (1000 * 60 * 60)) - (tickpartTime[i - 1]);
			//}
			//here we should check for holidays"official ones are 25th december and 1st january" 
		}
		else if (i == 0)
		{
			//tickpartTime_difference[i]=((tickpartTime[i]));
			number_Units_Eachpoint_Xaxis[i] = 0;//this because 1st point on x axis will be plotted as it is without reference to previous time,it is the begining point
			amount_Time_between_2Tikcs_with_OffTime[i] = 0;
			amount_Time_between_2Tikcs_without_OffTime[i] = 0;
			amount_Time_between_2Tikcs_with_OffTime_summed[i] = 0;
			amount_Time_between_2Tikcs_without_OffTime_summed[i] = 0;

			Weekly_Holidays_Time = 0;
			Vacancy_Festival_Holidays = 0;
			daily_closure_to_open_Time = 0;
			daily_BreakingTime = 0;
			Emergency_OffTime = 0;
			TotalOffTime = 0;

		}
	}

	//std::adjacent_difference(tickpartTime.begin(), tickpartTime.end(), tickpartTime_difference.begin());
	//epochpartTime_difference[0]=0; ////the first difference is calculated from beginning of hour so the first tickpartTime is the increase in time from zero beginning of hour

	// After function call 
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;

}
//default constructor
csv_time_bid_ask_difference::csv_time_bid_ask_difference()
	:csv_to_monowave_vectors()
{

}
//__host__

csv_time_bid_ask_difference::csv_time_bid_ask_difference(Worker* workerPtr)
	:csv_to_monowave_vectors(workerPtr)
{
	plot_flag = csv_time_bid_ask_difference_m;

	get_epochpartTime_difference();
	get_tickpartTime_difference();
	get_bidPrice_difference();
	get_bidPrice_difference_absolute();
	get_askPrice_difference();
	get_askPrice_difference_absolute();
	get_number_Units_Eachpoint_Xaxis();	

	std::cout << '\n';
	/*
	//17-9-2021 we will plot bid ask prices differences,ticks time differences	
	emit workerPtr->updateTable(this);
	mutex.lock();
	updateTable_waiting.wait(&mutex);
	mutex.unlock();
	emit workerPtr->plotGraph(this);
	mutex.lock();
	plotGraph_waiting.wait(&mutex);
	mutex.unlock();
	*/
}
