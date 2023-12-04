#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // Sort the array
        sort(nums.begin(), nums.end());

        // Fix the first element and use two pointers to find the other two
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int low = i + 1;
            int high = n - 1;
            int target = -nums[i]; // Set the target to make the sum zero

            while (low < high) {
                int currSum = nums[low] + nums[high];

                if (currSum == target) {
                    result.push_back({nums[i], nums[low], nums[high]});

                    // Skip duplicate values for the second element
                    while (low < high && nums[low] == nums[low + 1]) {
                        low++;
                    }

                    // Skip duplicate values for the third element
                    while (low < high && nums[high] == nums[high - 1]) {
                        high--;
                    }

                    // Move pointers
                    low++;
                    high--;
                } else if (currSum < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }

        return result;
    }
};

int main() {
    // Example usage
    vector<int> nums = {-1, 0, 1, 3, -1, -4, 6, 4, 2, 3, 1, -3, -3};
    
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);

    // Print the result
    for (const auto& triplet : result) {
        cout << "[";
        for (const auto& num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
