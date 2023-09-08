#include<iostream>
using namespace std;
int binarySearchR(int arr[], int l, int r, int key);

int main(){
    int n = 5, l=0;
    int arr[n]={1,3,6,8,44};
    int key1 = 3;
    int key2 = 44;
    int key3 = 5;

    int resultIndex1 = binarySearchR(arr, l, n-1, key1);
    int resultIndex2 = binarySearchR(arr, l, n-1, key2);
    int resultIndex3 = binarySearchR(arr, l, n-1, key3);
    cout<<resultIndex1<<endl;
    cout<<resultIndex2<<endl;
    cout<<resultIndex3<<endl;
    return 0;
}

int binarySearchR(int arr[], int l, int r, int key){
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            return binarySearchR(arr, mid+1, r, key);
        }
        if(arr[mid]>key){
            return binarySearchR(arr, l, mid-1, key);
        }
    }
    return -1;
}