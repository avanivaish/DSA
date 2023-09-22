#include<iostream>
using namespace std;

void waveSort(int arr[], int n);

int main(){
    int n = 8;
    int arr[n] = {3, 6, 1, 8, 4, 2, 9, 7};
    waveSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void waveSort(int arr[], int n){
    for(int i=1; i<n; i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        if(arr[i]>arr[i+1] && i<=n-2){
            swap(arr[i],arr[i+1]);
        }
    }
}