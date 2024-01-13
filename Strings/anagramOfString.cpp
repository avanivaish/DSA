#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2) {
    // Create arrays to store character counts
    int count1[26] = {0};
    int count2[26] = {0};

    // Traverse str1 and update count1
    for (char c : str1) {
        count1[c - 'a']++;
    }

    // Traverse str2 and update count2
    for (char c : str2) {
        count2[c - 'a']++;
    }

    // Calculate the total number of characters to be deleted
    int totalDeletions = 0;
    for (int i = 0; i < 26; i++) {
        totalDeletions += abs(count1[i] - count2[i]);
    }

    return totalDeletions;
}

int main() {
    // Example usage:
    string str1 = "bcadeh";
    string str2 = "hea";

    // Call the function and print the result
    int result = remAnagram(str1, str2);
    cout << "Minimum number of characters to be deleted: " << result << endl;

    return 0;
}
