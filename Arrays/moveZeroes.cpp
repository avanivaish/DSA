#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return;
        int nz=0, z=0;
        while(nz<nums.size()){
            if(nums[nz]!=0){
                int temp = nums[nz];
                nums[nz]=nums[z];
                nums[z]=temp;
                nz++;
                z++;
            }else{
                nz++;
            }
        }
    }
};

int main() {
    // Example usage
    Solution solution;

    // Initialize a vector with some values, including zeros
    vector<int> nums = {0, 1, 0, 3, 12};

    // Display the original vector
    cout << "Original Vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Call the moveZeroes method to move zeros to the end
    solution.moveZeroes(nums);

    // Display the modified vector
    cout << "Modified Vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
