#ifndef CSV_DIRECTIONAL_NONDIRECTIONAL_GENERAL_METHODS
#define CSV_DIRECTIONAL_NONDIRECTIONAL_GENERAL_METHODS

//here we make methods to calculate central tendency MEAN MODE MEDIAN
#include <vector>
#include <algorithm>    // std::sort

//#include <bits/stdc++.h> 
//using namespace std;

//finding mean of the ungrouped data in array
float mean(float arr[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum / n;
}
double mean(std::vector<double> vec);
void mean(std::vector<double>& vec, std::vector<double>& result)

//finding median of the ungrouped data in the array
float median(float arr[], int n) {
    //sort the array
    std::sort(arr, arr + n);
    if (n % 2 == 0)
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    return arr[n / 2];
}
double median(std::vector<double> vec);

//finding mode of ungrouped data
float mode(float arr[], int n) {
    // Sort the array 
    std::sort(arr, arr + n);

    //finding max frequency  
    int max_count = 1, res = arr[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            count++;
        else {
            if (count > max_count) {
                max_count = count;
                res = arr[i - 1];
            }
            count = 1;
        }
    }

    // when the last element is most frequent 
    if (count > max_count)
    {
        max_count = count;
        res = arr[n - 1];
    }

    return res;
}
double mode(std::vector<double> vec);

#endif  //CSV_DIRECTIONAL_NONDIRECTIONAL_GENERAL_METHODS