#include<iostream>
using namespace std;

int rotatedSortedArray(int arr[],int n,int k);
int getPivot(int arr[], int n);
int binarySearch(int arr[], int l, int h, int k);

int rotatedSortedArray(int arr[],int n,int k){
    int pivot = getPivot(arr, n);
    if(arr[pivot]<=k && k<=arr[n-1]){
        return binarySearch(arr,pivot,n-1,k);
    }
    else{
        return binarySearch(arr,0,pivot-1,k);
    }
}

int getPivot(int arr[], int n){
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(int arr[], int l, int h, int k){
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]>k){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int main(){
    int n = 8;
    int arr[n] = {30,32,45,78,15,20,24,29};
    int k = 78;
    cout<<rotatedSortedArray(arr,n,k)<<endl;
    return 0;
}

