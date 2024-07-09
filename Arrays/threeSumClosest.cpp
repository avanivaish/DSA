#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            while(start < end) {
                int sum = first + nums[start] + nums[end];
                if(sum == target) return target;
                if(abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    ans = sum;
                }
                if(sum > target) end--;
                else start++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { -1, 2, 1, -4 };
    int target = 1;
    int result = sol.threeSumClosest(nums, target);
    cout << "The closest sum to " << target << " is " << result << endl;
    return 0;
}
