#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstringWithKUniqueChars(string s, int K) {
    int maxLength = -1; // Initialize to -1 (no possible substring)
    unordered_map<char, int> charCount;
    int left = 0;
    int uniqueCount = 0;

    for (int right = 0; right < s.length(); ++right) {
        if (charCount[s[right]] == 0) { //found new element
            if (uniqueCount == K) {
                while (--charCount[s[left]] > 0) {
                    ++left;
                }
                ++left; // Move the left pointer past the repeated character
            } else {
                ++uniqueCount;
            }
        }
        ++charCount[s[right]];

        if (uniqueCount == K) {
            maxLength = max(maxLength, right - left + 1);
        }
    }

    return maxLength;
}

int main() {
    string s = "aabacbebebe";
    int K = 3;
    int result = longestSubstringWithKUniqueChars(s, K);
    cout << result << endl; // Output should be 7
    string a = "avanivaish";
    int n = 2;
    int result_a = longestSubstringWithKUniqueChars(a, n);
    cout << result_a << endl; // Output should be 
    return 0;
}
