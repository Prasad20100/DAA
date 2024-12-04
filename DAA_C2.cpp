#include <iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum) {
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] <= j)
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            else
                subset[i][j] = subset[i - 1][j];
        }
    }

    return subset[n][sum];
}

int main() {
    int n, sum;

    cout << "Enter number of elements: ";
    cin >> n;

    int set[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    cout << "Enter sum: ";
    cin >> sum;

    if (isSubsetSum(set, n, sum))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
