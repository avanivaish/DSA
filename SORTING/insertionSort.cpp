#include<iostream>
using namespace std;

void insertionSort(int arr[], int n);

int main(){
    int n = 7;
    int arr[n]={105,9,313,35,55,58,12};
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}