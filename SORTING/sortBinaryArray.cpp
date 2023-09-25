#include<iostream>
using namespace std;

void sortBinaryArray(int arr[], int n);

int main(){
    int n = 10;
    int arr[n]={1, 0, 1, 1, 1, 1, 1, 0, 0, 0,};
    sortBinaryArray(arr,n);
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}

void sortBinaryArray(int arr[], int n){
    int low = 0, high = n-1;
    while(low<=high){
        if(arr[low]==0){low++;}
        else{
            if(arr[low]==1 and arr[high]==0){
                //swap
                int temp = arr[low];
                arr[low]=arr[high];
                arr[high]=temp;
                low++;
                high--;
            }
            else{high--;}
        }
    }
}