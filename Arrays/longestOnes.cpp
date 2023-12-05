#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount = 0;
        int ans = 0;
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] == 0) {
                zeroCount++;
            }
            while(zeroCount > k) {
                if(nums[i] == 0) {
                    zeroCount--;
                }
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0};
    int k = 3;
    int result = solution.longestOnes(nums, k);
    cout << "The length of the longest subarray with at most " << k << " zeros is: " << result << endl;

    return 0;
}
