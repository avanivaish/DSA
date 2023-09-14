#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n);

int main(){
    int n = 7;
    int arr[n]={105,9,313,35,55,58,12};
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void bubbleSort(int arr[], int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}