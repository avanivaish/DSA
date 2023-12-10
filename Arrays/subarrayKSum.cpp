#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        int sum = 0;
        int count = 0;
        m.insert({0, 1});
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            auto it = m.find(sum - k);
            if (it != m.end()) {
                count += it->second;
            }

            it = m.find(sum);
            if (it != m.end()) {
                it->second++;
            } else {
                m.insert({sum, 1});
            }
        }
        return count;
    }
};

int main() {
    // Example usage:
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 10;
    int result = sol.subarraySum(nums, k);
    
    cout << "The number of subarrays with sum equal to " << k << " is: " << result << endl;

    return 0;
}
