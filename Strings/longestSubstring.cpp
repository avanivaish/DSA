#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_map<char, int> mp; // Use char as the key type
        int ans = INT8_MIN;;

        while (j < s.size()) {
            if (mp.find(s[j]) == mp.end()) {
                ans = max(ans, j - i + 1);
                mp[s[j]] = j;
            } else {
                int index = mp[s[j]];
                while (i <= index) {
                    mp.erase(s[i]);
                    i++;
                }
                mp[s[j]] = j;
            }
            j++;
        }

        if (ans == INT8_MIN) {
            return 0;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string input = "abcabcbb"; // Replace this with your input string
    int result = solution.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}
