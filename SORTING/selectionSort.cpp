#include<iostream>
using namespace std;

void selectionSort(int arr[], int n);

int main(){
    int n= 6;
    int arr[n]={9,6,1,4,2,0};
    selectionSort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

//Time Complexity : O(n^2)
//Space Complexity : O(1)
