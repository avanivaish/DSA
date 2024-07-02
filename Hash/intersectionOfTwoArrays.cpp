#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> commonset;

        for (auto el : nums2) {
            if (set1.contains(el)) commonset.insert(el);
        }
        vector<int> ans(commonset.begin(), commonset.end());
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = solution.intersection(nums1, nums2);

    cout << "Intersection of nums1 and nums2: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    nums1 = {4, 9, 5};
    nums2 = {9, 4, 9, 8, 4};
    result = solution.intersection(nums1, nums2);

    cout << "Intersection of nums1 and nums2: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
