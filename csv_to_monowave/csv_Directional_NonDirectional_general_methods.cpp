#include "csv_Directional_NonDirectional_general_methods.h"

double mean(std::vector<double> vec)
{
    double sum = 0;
    for (int i = 0; i < vec.size(); i++)
        sum += vec[i];

    return sum / vec.size();
}
void mean(std::vector<double>& vec,std::vector<double>& result)
{
    double sum = 0;
    for (int i = 0; i < vec.size(); i++)
        sum += vec[i];

    return sum / vec.size();
}
double median(std::vector<double> vec)
{
    //sort the array
    std::sort(vec.begin(), vec.end());
    if (vec.size() % 2 == 0)
        return (vec[(vec.size() / 2) - 1] + vec[vec.size() / 2]) / 2;
    return vec[vec.size() / 2];
}

double mode(std::vector<double> vec)
{
    // Sort the array 
    std::sort(vec.begin(), vec.end());

    //finding max frequency  
    int max_count = 1, res = vec[0], count = 1;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] == vec[i - 1])
            count++;
        else {
            if (count > max_count) {
                max_count = count;
                res = vec[i - 1];
            }
            count = 1;
        }
    }

    // when the last element is most frequent 
    if (count > max_count)
    {
        max_count = count;
        res = vec[vec.size() - 1];
    }

    return res;
}