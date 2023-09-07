#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int key);

int main(){
    int n = 5;
    int arr[n]={1,3,6,8,44};
    int key1 = 3;
    int key2 = 44;
    int key3 = 5;

    int resultIndex1 = binarySearch(arr,n,key1);
    int resultIndex2 = binarySearch(arr,n,key2);
    int resultIndex3 = binarySearch(arr,n,key3);
    cout<<resultIndex1<<endl;
    cout<<resultIndex2<<endl;
    cout<<resultIndex3<<endl;
    return 0;
}

int binarySearch(int arr[], int n, int key){
    int start = 0;
    int end = n-1;
    int mid = (start + (end-start)/2);
    
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            end = mid-1;
        }
        if(arr[mid]<key){
            start=mid+1;
        }
        mid = (start + (end-start)/2);
    }
    return -1;
}