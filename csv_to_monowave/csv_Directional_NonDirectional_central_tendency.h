#ifndef CSV_DIRECTIONAL_NONDIRECTIONAL_CENTRAL_TENDENCY
#define CSV_DIRECTIONAL_NONDIRECTIONAL_CENTRAL_TENDENCY

//here we make class to calculate central tendency MEAN MODE MEDIAN
#include <vector>
#include <algorithm>    // std::sort
#include <map>
/*
template <typename T, typename Total, size_t N>
class Moving_Average
{
  public:
    Moving_Average& operator()(T sample)
    {
        total_ += sample;
        if (num_samples_ < N)
            samples_[num_samples_++] = sample;
        else
        {
            T& oldest = samples_[num_samples_++ % N];
            total_ -= oldest;
            oldest = sample;
        }
        return *this;
    }

    operator double() const { return total_ / std::min(num_samples_, N); }

  private:
    T samples_[N];
    size_t num_samples_{0};
    Total total_{0};
};*/
class Central_Tendency
{
public:
	//default constructor
	Central_Tendency();
	//Central_Tendency();
public:
	std::map<int, std::vector<double>> map_subsegment_price_differences;
    std::map<int, double> map_subsegment_price_differences_totals;

public:
    void mean(std::vector<double>& vec, std::vector<double>& result)
	{
        total_ += sample;

		for (int i = 0; i < vec.size(); i++)
		{
			sum += vec[i];

		}

		mean_m= sum / vec.size();
	}
};
////////////chatgpt///////
/*
Sure, here's an updated version of the `CentralTendency` class that works on a single new data point and stores the result in a result vector:

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class CentralTendency {
private:
    int size;

public:
    CentralTendency() {
        size = 0;
    }

    double mean(double new_data, vector<double>& result) {
        double current_mean = 0;
        if (size > 0) {
            current_mean = result.back();
        }
        size++;
        double new_mean = current_mean + (new_data - current_mean) / size;
        result.push_back(new_mean);
        return new_mean;
    }

    double median(double new_data, vector<double>& result) {
        result.push_back(new_data);
        size++;
        sort(result.begin(), result.end());
        int mid = size / 2;
        double median;
        if (size % 2 == 0) {
            median = (result[mid - 1] + result[mid]) / 2.0;
        } else {
            median = result[mid];
        }
        return median;
    }

    int mode(double new_data, vector<double>& result) {
        result.push_back(new_data);
        size++;
        unordered_map<int, int> freq_map;
        for (int i = 0; i < size; i++) {
            freq_map[result[i]]++;
        }
        int mode = result[0], max_freq = 1;
        for (auto it = freq_map.begin(); it != freq_map.end(); it++) {
            if (it->second > max_freq) {
                mode = it->first;
                max_freq = it->second;
            }
        }
        return mode;
    }
};

int main() {
    vector<double> result;

    CentralTendency ct;

    double new_data = 5.5; // Example new data point, you can replace it with your own

    double mean = ct.mean(new_data, result);
    cout << "Mean of data: " << mean << endl;

    double median = ct.median(new_data, result);
    cout << "Median of data: " << median << endl;

    int mode = ct.mode(new_data, result);
    cout << "Mode of data: " << mode << endl;

    return 0;
}
```

In this updated version, the `CentralTendency` constructor is empty, since there is no need to initialize any member variables.

The `mean(double new_data, vector<double>& result)`, `median(double new_data, vector<double>& result)`, and `mode(double new_data, vector<double>& result)` methods take the new data point `new_data` as an argument and calculate the corresponding central tendency measure for the updated data set that includes the new data point. They use a reference to a `result` vector to store the calculated central tendency measure for each update.

In the `main()` function, a `result` vector is created to store the calculated central tendency measures for each update. An instance of the `CentralTendency` class is created. The `mean(double new_data, vector<double>& result)`, `median(double new_data, vector<double>& result)`, and `mode(double new_data, vector<double>& result)` methods are called on this instance with the new data point `new_data` and the `result` vector, and the corresponding central tendency measures are printed to the console. The `result` vector is updated with the new central tendency measure for each method.
*/
#endif //CSV_DIRECTIONAL_NONDIRECTIONAL_CENTRAL_TENDENCY