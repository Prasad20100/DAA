#include <iostream>
#include <string>
using namespace std;

// Function to check if it is possible to transform s1 to s2
bool canTransform(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    // If s1 is shorter than s2, it's impossible to transform
    if (m < n)
        return false;

    // Start comparing characters from both strings
    int j = 0; // Index for s2

    for (int i = 0; i < m; i++) {
        // If s1's current character matches s2's current character
        // (either both are the same letter in uppercase or we convert s1[i] to uppercase)
        if (j < n && (toupper(s1[i]) == s2[j])) {
            j++; // Move to the next character in s2
        } 
        // If s1[i] is a lowercase letter, it can either be converted to uppercase or deleted
        else if (isupper(s1[i])) {
            // If there's a mismatch with an uppercase letter, transformation fails
            return false;
        }
    }

    // If we have matched all characters of s2, then transformation is possible
    return (j == n);
}

int main() {
    string s1, s2;

    // Accept the input strings
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    // Check if it's possible to transform s1 into s2
    if (canTransform(s1, s2))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
