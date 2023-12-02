#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        int left = INT16_MAX;
        int mid = INT16_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid) {
                return true;
            } else if (nums[i] > left && nums[i] < mid) {
                mid = nums[i];
            } else if (nums[i] < left) {
                left = nums[i];
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << "Example 1: " << (solution.increasingTriplet(nums1) ? "true" : "false") << endl;

    // Example 2
    vector<int> nums2 = {5, 4, 3, 2, 1};
    cout << "Example 2: " << (solution.increasingTriplet(nums2) ? "true" : "false") << endl;

    return 0;
}
