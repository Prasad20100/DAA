#include <iostream>
#include <algorithm>

using namespace std;

// Function to generate all subsets using bit masking
void findSubsets(int nums[], int n) {
    int subsetCount = (1 << n); // Total subsets = 2^n
    int subsets[1024][10];     // Assuming a maximum of 1024 subsets and 10 elements per subset
    int subsetSizes[1024] = {0}; // Array to store sizes of each subset
    int subsetIndex = 0;

    for (int mask = 0; mask < subsetCount; mask++) {
        int currentSubset[10], currentSize = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                currentSubset[currentSize++] = nums[i];
            }
        }

        // Sort current subset to handle duplicates
        sort(currentSubset, currentSubset + currentSize);

        // Check if subset is unique before storing
        bool isUnique = true;
        for (int i = 0; i < subsetIndex; i++) {
            if (currentSize == subsetSizes[i]) {
                bool same = true;
                for (int j = 0; j < currentSize; j++) {
                    if (currentSubset[j] != subsets[i][j]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    isUnique = false;
                    break;
                }
            }
        }

        // Store subset if unique
        if (isUnique) {
            for (int i = 0; i < currentSize; i++) {
                subsets[subsetIndex][i] = currentSubset[i];
            }
            subsetSizes[subsetIndex] = currentSize;
            subsetIndex++;
        }
    }

    // Print all unique subsets
    cout << "The distinct subsets are:\n";
    for (int i = 0; i < subsetIndex; i++) {
        cout << "{ ";
        for (int j = 0; j < subsetSizes[i]; j++) {
            cout << subsets[i][j] << " ";
        }
        cout << "}\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    int nums[10]; // Assuming a maximum of 10 elements in the set
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Generate and display all distinct subsets
    findSubsets(nums, n);

    return 0;
}
