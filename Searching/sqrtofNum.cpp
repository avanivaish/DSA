#include<iostream>
using namespace std;

int binarySearch(int n);

int main(){
    int n = 49;
    cout<<binarySearch(n)<<endl;
    int n1=83;
    cout<<binarySearch(n1)<<endl;
    return 0;
}

int binarySearch(int n){
    int s=0, e=n;
    int mid =s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        int sq=mid*mid;
        if(sq==n){
            return mid;
        }
        if(sq<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}