#include<iostream>
using namespace std;

int getPivotIndex(int arr[], int n);

int main(){
    int n = 6;
    int arr[n]={21,33,46,8,9,15};
    cout<<getPivotIndex(arr,n)<<endl;
    return 0;
}

int getPivotIndex(int arr[], int n){
    int s=0, e=n-1;
    int mid = s + (e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }

        mid=s+(e-s)/2;
    }
    return s;
}