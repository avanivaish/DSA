#include<iostream>
using namespace std;

int main(){
    int n =5;
    int nums[n] = {3,4,5,1,2};

    int low = 0;
    int high = n-1;
    
    if (nums[low]<=nums[high]){
        cout<<nums[low];
        return 0;
    }

    while(low<=high){
        int mid = (low+high)/2;

        if(nums[mid]<nums[mid-1]){
            cout<<nums[mid];
            return 0;
        }
        else if(nums[mid+1]<nums[mid]){
            cout<<nums[mid+1];
            return 0;
        }
        else if(nums[low]<=nums[mid]){
            low = mid+1;
        }
        else if(nums[mid]<=nums[high]){
            high = mid-1;
        }
    }
    return 0;
}