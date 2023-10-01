#include<iostream>
using namespace std;
void subsets(int arr[], int n);
int main(){
    int n = 4;
    int arr[4]={1,2,3,4};
    subsets(arr,n);
    return 0;
}

void subsets(int arr[], int n){
    for(int i=0; i<(1<<n);i++){ //1<<n == 2^n
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }cout<<endl;
    }
}