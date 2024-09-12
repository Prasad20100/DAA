#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A structure to represent a shop with start and end times
struct Shop {
    int start, end;
};

// Comparator function to sort shops by their end time
bool compare(Shop s1, Shop s2) {
    return s1.end < s2.end;
}

// Function to calculate the maximum number of shops K people can visit
int maxShopsVisited(int n, vector<int>& S, vector<int>& E, int K) {
    vector<Shop> shops(n);
    
    // Initialize shops with start and end times
    for (int i = 0; i < n; i++) {
        shops[i] = {S[i], E[i]};
    }

    // Sort shops based on their ending time
    sort(shops.begin(), shops.end(), compare);

    vector<int> persons(K, 0);  // To track the end time of the last shop visited by each person
    int shopCount = 0;          // To count the number of shops visited in total

    // Iterate through each shop
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < K; j++) {
            // If the current person can visit the shop (i.e., no collision in timings)
            if (persons[j] <= shops[i].start) {
                persons[j] = shops[i].end;  // Update the end time for this person
                shopCount++;  // Increment the count of visited shops
                break;  // Move to the next shop as this shop is assigned to a person
            }
        }
    }

    return shopCount;  // Return the total number of shops visited
}

int main() {
    int n, K;

    // Input number of shops
    cout << "Enter the number of shops: ";
    cin >> n;

    vector<int> S(n), E(n);

    // Input start and end times of shops
    cout << "Enter the start times of the shops: ";
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    cout << "Enter the end times of the shops: ";
    for (int i = 0; i < n; i++) {
        cin >> E[i];
    }

    // Input number of people
    cout << "Enter the number of persons: ";
    cin >> K;

    // Calculate the maximum number of shops that can be visited
    int result = maxShopsVisited(n, S, E, K);

    // Output the result
    cout << "Maximum number of shops that can be visited: " << result << endl;

    return 0;
}
