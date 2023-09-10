#include<iostream>
using namespace std;
int allocateBooks(int arr[],int n,int m);
bool isPossibleSolution(int arr[], int n, int m, int mid);

int main(){
    int n = 4;
    int m = 5;
    int arr[n]={12,34,67,90};
    cout<<allocateBooks(arr,n,m)<<endl;
    return 0;
}

int allocateBooks(int arr[], int n, int m){
    int s=0, sum =0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    int e=sum;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(m>n){
            return ans;
        }
        if(isPossibleSolution(arr,n,m,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

bool isPossibleSolution(int arr[], int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;
    for(int i=0; i<n; i++){
        if(pageSum+arr[i]<=mid){
            pageSum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}