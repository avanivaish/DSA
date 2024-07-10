#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        if (n == 0 || m == 0) return 0;

        // Initialize dp matrix
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int max_side = 0;

        // Fill the dp matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // First row or first column
                    } else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }

        return max_side;
    }
};

// Example usage:
int main() {
    Solution sol;
    int n = 6;
    int m = 5;
    vector<vector<int>> mat = {
        {0, 1, 1, 0, 1}, 
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };
    int result = sol.maxSquare(n, m, mat);
    cout << "The maximum side length of a square with all 1s is: " << result << endl; // Output: 3
    return 0;
}
