#ifndef CSV_TO_MONOWAVE_VECTORS
#define CSV_TO_MONOWAVE_VECTORS

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <ninety47/dukascopy.h>
#include <ninety47/dukascopy/defs.h>
//#include "../Worker.h"
//for DIRECTIONAL_NONDIRECTIONAL_DEGREE_CLASS
//#include "Directional_NonDirectional_degree_class.h"
#include "../utils/utils.h" 
//17-9-2021 this include to make emit works for graphing in QT
//#include <QObject>
//#include "../Worker.h"
#include "../global.h"

class Worker;
class csv_to_monowave_vectors
{
//private:
	//csv_to_monowave_vectors() = delete;
public:
	csv_to_monowave_vectors();
	csv_to_monowave_vectors(Worker* workerPtr);
//public:
//	friend class directional_nondirectional_degree_class;
	//private:
		//21-9-2021 this is made public so that pointer in Qt thread worker could read them without setters and getters BUT I should make setters and getters if it worked well
public:
//	std::vector<directional_nondirectional_degree_class> D_ND_degree_vec;

	//here we make flags to update plots for each method avoiding  empty vectors
	int plot_flag = 0;
	int csv_bin = 1;
	int	csv_time_bid_ask_difference_m = 2;
	int csv_min_time_with_price_difference_m = 3;
	int csv_directional_nondirectional_degree_class_m = 4;

	//FIRST we get the data from bin file to work with it
	std::string path;//="GBPJPY_2020_08_30_.bin";
	std::ifstream data_file;//(path);
	std::string line;
	int lineCounter;//={0};

	// Declare data storage  
	std::vector<unsigned int> epochpartTime;
	std::vector<unsigned int> tickpartTime;

	std::vector<long long> tickTime;
	std::vector<unsigned int> bidPrice;
	std::vector<unsigned int> askPrice;
	std::vector<unsigned int> bidVolume;
	std::vector<unsigned int> askVolume;
};
#endif //CSV_TO_MONOWAVE_VECTORS