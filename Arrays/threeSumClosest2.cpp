#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        int ans = 0;
        
        for (int i = 0; i < arr.size() - 2; ++i) {
            int first = arr[i];
            int start = i + 1;
            int end = arr.size() - 1;
            
            while (start < end) {
                int sum = first + arr[start] + arr[end];
                
                if (sum == target) return target;
                
                int current_diff = abs(sum - target);
                
                if (current_diff < diff) {
                    diff = current_diff;
                    ans = sum;
                } else if (current_diff == diff) {
                    ans = max(ans, sum);
                }
                
                if (sum > target) {
                    --end;
                } else {
                    ++start;
                }
            }
        }
        
        return ans;
    }
};

// Example usage
#include <iostream>

int main() {
    Solution sol;
    vector<int> arr1 = {-7, 9, 8, 3, 1, 1};
    int target1 = 2;
    int result1 = sol.threeSumClosest(arr1, target1);
    cout << "Output: " << result1 << endl; // Output should be 2

    vector<int> arr2 = {5, 2, 7, 5};
    int target2 = 13;
    int result2 = sol.threeSumClosest(arr2, target2);
    cout << "Output: " << result2 << endl; // Output should be 14

    return 0;
}
