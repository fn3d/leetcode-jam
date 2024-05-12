/*

A function that takes in a sorted array of integers, and returns the first
pair of elements that sum to zero, if one exists. If no such pair is found,
the function should return an empty array.

function:   sumZeroWithoutMultiplePointers (O(n^2))
input:      vector arr (sorted array of integers)
output:     vector (integers in the list that add up to zero)

function:   sumZeroWithMultiplePointers (O(n))
input:      vector arr (sorted array of integers)
output:     vector (integers in the list that add up to zero)

function:   countUniqueValues (O(n))
input:      vector arr (sorted array of integers)
output:     int (arr of unique values in the array)

*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> sumZeroWithoutMultiplePointers(vector<int>& arr) {
    
    vector<int> result = {NULL, NULL};
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == 0) {
                result[0] = arr[i];
                result[1] = arr[j];
                return result;
            }
        }
    }
    return result;
}

vector<int> sumZeroWithMultiplePointers(vector<int>& arr) {
    
    int left = 0;
    int right = arr.size() - 1;
    vector<int> result = {NULL, NULL};

    while (left < right) {
        const int sum = arr[left] + arr[right];
        if (sum == 0) {
            result[0] = arr[left];
            result[1] = arr[right];
            return result;
        } else if (sum > 0) {
            right--;
        } else {
            left++;
        }
    }
    return result;
}

int countUniqueValues(vector<int>& arr) {
    
    if (arr.size() == 0) {
        return 0;
    }

    int i = 0;

    // Because we visit one value only once to compare it
    // with other items in the array, instead of running
    // a nested for loop, we will just replace the current
    // item being pointed to with the item it is being
    // evaluated with, so that we automatically pull the
    // next value when comparing it with the ones ahead.
    // This will give O(n) time complexity instead of O(n^2)
    // if nested for loop was used.
    for (int j = 1; j < arr.size(); j++) {
        if (arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1;
}

int main() {

    vector<int> testSortedArr{-3, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> result1 = sumZeroWithoutMultiplePointers(testSortedArr);
    vector<int> result2 = sumZeroWithMultiplePointers(testSortedArr);

    cout << "[ " + to_string(result2[0]) + ", " + to_string(result2[1]) + " ]" + '\n' + '\n';
}

