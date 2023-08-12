#include<iostream>
using namespace std;

int main(){
    int n = 7;
    int nums[n] = {4,5,6,7,0,1,2};
    int target = 0;

    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(nums[mid]==target){
            cout<<mid<<endl;
            return 0;
        }
        else if(nums[low]<=nums[mid]){
            //part 1 - sorted
            if(nums[low]<=target && nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else if(nums[mid]<=nums[high]){
            //par 2 - sorted
            if (nums[mid]<target && nums[high]>=target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;    
}