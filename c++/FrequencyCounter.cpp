/*

A simple implementation of the Frequency Counter problem solving pattern.

function:   same_without_frequency_counting
input:      array1, array2
output:     bool

function:   same_with_frequency_counting_case1
input:      array1, array2
output:     bool

function:   same_with_frequency_counting_case2
intput:     array1, array2
output:     bool

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool same_without_frequency_counting(vector<int>& array1, vector<int>& array2) {
    
    // Return false if the arrays have different lengths
    if (array1.size() != array2.size()) {
        return false;
    }

    // Iterate through each element in array1
    for (int i = 0; i < array1.size(); i++) {
        // Return false if the square of the element is not in array2
        std::vector<int>::iterator itr;
        itr = std::find(array2.begin(), array2.end(), array1[i] * array1[i]);

        // Return false even if the square of one item is not found
        if (itr == array2.end()) {
            return false;
        } else {
            // Remove the element from array2 if it is present
            array2.erase(itr);
        }
    }
    
    // Return true if all the elements are present and the lengths match
    return true;
}

int main() {
    vector<int> array1 = {2, 3, 4, 5, 6};
    vector<int> array2 = {4, 9, 16, 25, 36};

    std::cout << same_without_frequency_counting(array1, array2) << '\n' << '\n';
}