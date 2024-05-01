/*

A simple implementation of the Frequency Counter problem solving pattern.

function:   sameWithoutFrequencyCounting (O(n^2))
input:      array1, array2
output:     bool

function:   sameWithFrequencyCounting (O(n))
input:      array1, array2
output:     bool

function:   validAnagram (O(n))
intput:     array1, array2
output:     bool

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool sameWithoutFrequencyCounting(vector<int>& array1, vector<int>& array2) {
    
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

bool sameWithFrequencyCounting(vector<int>& array1, vector<int>& array2) {

    // Return false if the arrays have different lengths
    if (array1.size() != array2.size()) {
        return false;
    }

    std::map<std::string, int> freqCounter1 = {};
    std::map<std::string, int> freqCounter2 = {};

    // Populate freqCounter1 with the frequency of each element in array1 and array2
    for (int i = 0; i < array1.size(); i++) {
        freqCounter1[std::to_string(array1[i])] = freqCounter1[std::to_string(array1[i])] + 1;
    }

    for (int i = 0; i < array2.size(); i++) {
        freqCounter2[std::to_string(array2[i])] = freqCounter2[std::to_string(array2[i])] + 1;
    }

    // Iterate through the keys in freqCounter1
    std::map<std::string, int>::iterator it;
    for (it = freqCounter1.begin(); it != freqCounter1.end(); it++) {
        // Compute the square to compare with freqCounter1 entries
        int key = std::stoi(it->first) * std::stoi(it->first);
        // Now check if the calculated square exist as a key in freqCounter2,
        // and that the frequencies in both hashmaps is the same for related.
        if ((freqCounter2.count(std::to_string(key)) == 0) ||  \
            (freqCounter1[it->first] != freqCounter2[std::to_string(key)])) {
                return false;
            }
    }

    return true;
}

bool validAnagram(std::string& str1, std::string& str2) {

    std::map<char, int> freqCounter = {};

    for (int i = 0; i < str1.length() ; i++) {
        char currentElement = str1[i];
        freqCounter[currentElement] = freqCounter[currentElement] + 1;
    }

    // We run through the second string to find each character
    // in the frequency counter map, and decrement counter in the
    // map every time we find a specific character.
    std::string::iterator itr;
    for (int i = 0; i < str2.length(); i++) {
        itr = std::find(str2.begin(), str2.end(), freqCounter[i]);
        if (itr == str2.end()) {
            cout << "chicken" << endl;
            return false;
        } else {
            freqCounter[i] -= 1;
        }
    }
    
    return true;
}

int main() {
    vector<int> array1 = {2, 3, 4, 5, 6, 7};
    vector<int> array2 = {4, 9, 16, 25, 36, 49};

    //std::cout << sameWithFrequencyCounting(array1, array2) << '\n';

    std::string testStr1 = "color";
    std::string testStr2 = "cloor";

    cout << validAnagram(testStr1, testStr2) << endl;
}