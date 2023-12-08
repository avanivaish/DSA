#include<iostream>
using namespace std;

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int i = 0, j = 0;
        while (i < S.length() && j < T.length()) {
            if (T[j] >= '0' && T[j] <= '9') {
                int x = T[j] - '0';
                j++;
                while (j < T.length() && T[j] >= '0' && T[j] <= '9') {
                    x *= 10;
                    x += (T[j] - '0');
                    j++;
                }
                i += x;
            } else {
                if (S[i] == T[j]) {
                    i++;
                    j++;
                } else {
                    return 0;
                }
            }
        }
        if (i != S.length()) return 0;
        return 1;
    }
};

int main() {
    Solution solution;

    // Example 1
    string S1 = "abc";
    string T1 = "abc";
    cout << "Example 1: " << solution.checkCompressed(T1, S1) << endl;

    // Example 2
    string S2 = "a2b2c";
    string T2 = "aabbcc";
    cout << "Example 2: " << solution.checkCompressed(T2, S2) << endl;

    // Example 3
    string S3 = "a11b";
    string T3 = "abbbbbbbbbb";
    cout << "Example 3: " << solution.checkCompressed(T3, S3) << endl;

    return 0;
}
