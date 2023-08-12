#include<iostream>
using namespace std;

int main(){
    //int l = 5;
    //int nums[5]= {2,7,11,25,8};
    //int target = 10;

    int l,target;
    cout<<"Enter Length of Array: ";
    cin>>l;
    int nums[l];
    cout<<"Enter elements of Array: ";
    for (int i =0; i<l; i++){
        cin>>nums[i];
    }
    cout<<"Enter Target: ";
    cin>>target;
    
    for (int i=0; i<l-2; i++){
        for (int j=i+1; j<l; j++){
            if(nums[i]+nums[j]==target){
                cout<<"[" << i << "," << j << "]" <<endl;
                break;
            }
        }
    }
    return 0;
}

