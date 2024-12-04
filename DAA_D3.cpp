#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsets
void generateSubsets(const vector<int>& arr, int index, vector<int>& currentSubset) {
    // Base case: if index has reached the end of the array, return
    if (index == arr.size()) {
        // Print the current subset
        for (int i = 0; i < currentSubset.size(); i++) {
            cout << currentSubset[i] << " ";
        }
        cout << endl;
        return;
    }
    
    // Include the current element in the subset
    currentSubset.push_back(arr[index]);
    // Recur for the next element
    generateSubsets(arr, index + 1, currentSubset);
    
    // Exclude the current element from the subset (backtrack)
    currentSubset.pop_back();
    // Recur for the next element without including the current one
    generateSubsets(arr, index + 1, currentSubset);
}

int main() {
    vector<int> arr = {1, 2, 3}; // Input array
    vector<int> currentSubset;    // Temporary vector to hold current subset

    // Call the recursive function to generate and print all subsets
    cout << "Subsets of the array are:" << endl;
    generateSubsets(arr, 0, currentSubset);
    
    return 0;
}
