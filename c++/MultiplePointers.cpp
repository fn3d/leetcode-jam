/*

A function that takes in a sorted array of integers, and returns the first
pair of elements that sum to zero, if one exists. If no such pair is found,
the function should return an empty array.

function:   sumZeroWithoutMultiplePointers (O(n^2))
input:      vector array1, vector array2
output:     vector

function:   sumZeroWithMultiplePointers (O(n))
input:      vector array1, vector array2
output:     vector

*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> sumZeroWithoutMultiplePointers(vector<int>& number) {
    vector<int> result = {NULL, NULL};
    for (int i = 0; i < number.size(); i++) {
        for (int j = i + 1; j < number.size(); j++) {
            if (number[i] + number[j] == 0) {
                result[0] = number[i];
                result[1] = number[j];
                return result;
            }
        }
    }
    return result;
}

vector<int> sumZeroWithMultiplePointers(vector<int>& number) {
    int left = 0;
    int right = number.size() - 1;
    vector<int> result = {NULL, NULL};

    while (left < right) {
        const int sum = number[left] + number[right];
        if (sum == 0) {
            result[0] = number[left];
            result[1] = number[right];
            return result;
        } else if (sum > 0) {
            right--;
        } else {
            left++;
        }
    }
    return result;
}

int main() {

    vector<int> testSortedArr{-3, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> result1 = sumZeroWithoutMultiplePointers(testSortedArr);
    vector<int> result2 = sumZeroWithMultiplePointers(testSortedArr);

    cout << "[ " + to_string(result2[0]) + ", " + to_string(result2[1]) + " ]" + '\n' + '\n';
}

