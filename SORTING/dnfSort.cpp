#include<iostream>
using namespace std;

void dnfSort(int arr[], int n);

int main(){
    int n = 8;
    int arr[n]={0,1,2,2,1,2,0,1};
    dnfSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void dnfSort(int arr[], int n){
    int low=0, mid =0, high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}