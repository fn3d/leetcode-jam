/*

The sliding window pattern is used to solve problems that involve finding a 
sub-array / sequence of elements that meet certain conditions. It involves
creating a "window" inside the array which moves through the array, and
allows performing operations on that sub-set.

For example, let's assume we have an array and a fixed number which can be
used as the size of the sub-array (the window). Now, instead of computing
the sum of each sub-array independently (O(n^2)), we just slide the window
from left to right, and update the sum based on the first value leaving
and a new value entering the end of the sub-array. This will give us O(n).

function:   maxSumSubArray (O(n))
input:      array
output:     maximum sum of a subarray in the provided array

function:   maxAvgSubArray (O(n))
input:      array
output:     maximum average value among all subarrays of length 'k'

*/

#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int maxSumSubArray(vector<int>& array) {

    int start, end, maxSum, currSum = 0;

    while (end < array.size()) {
        currSum += array[end];
        maxSum = max(maxSum, currSum);
        if (currSum < 0) {
            currSum = 0;
            // Although start is not being used in this function,
            // it only serves as a utility for potential future
            // requirements, as it helps define the "window".
            start = end + 1;
        }
        end++;
    }

    return maxSum;
}

vector<float> maxAvgSubArray(vector<float> array, int k) {

    float start = 0, end = 0, currSum = 0, maxStart = 0, maxEnd = 0;
    float maxAvg = -numeric_limits<float>::max();

    while (end < array.size()) {
        currSum += array[end];
        // If the window is of the desired size
        if (end - start + 1 >= k) {
            float avg = currSum / (end - start + 1);
            // If the calculated average for current window position
            // is greater than the previous average calculated, then
            // set the current window positions as the maximum ones.
            if (avg > maxAvg) {
                maxAvg = avg;
                maxStart = start;
                maxEnd = end;
            }
        }
        if (currSum < 0) {
            currSum = 0;
            start = end + 1;
        }
        end++;
    }

    vector<float> sliced(array.begin() + maxStart, array.begin() + maxEnd + 1);
    return sliced;
}

int main() {

    vector<int> testArr1 = {0, 1, -2, -3, 4, 5, 6, 7};
    int maxSum = maxSumSubArray(testArr1);

    vector<float> testArr2 = {0, 1, -2, -3, 4, 5, 6, 7};
    vector<float> maxAvg = maxAvgSubArray(testArr2, 3);

    for (const auto& item : maxAvg) {
        cout << item << '\n';
    }
}