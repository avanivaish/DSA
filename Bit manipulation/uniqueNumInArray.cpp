//FIND UNIQUE NUMBER IN ARRAY PRESENT - REST EVERY OTHER ELEMENT IS PRESENT TWICE
//FIND TWO UNIQUE NUMBERS IN ARRAY - CONTINUATION

#include<iostream>
using namespace std;
int unique(int arr[], int n);
void uniqueTwo(int arr[], int n); 
int main(){
    int n= 7;
    int arr[n]={1,2,3,4,1,2,3};
    cout<<unique(arr,n)<<endl;
    int n1 = 6;
    int arr1[n1]={8,5,2,8,3,3};
    uniqueTwo(arr1,n1);
    return 0;
}
//q1
int unique(int arr[], int n){
    int xorsum=0;
    for(int i=0; i<n;i++){
        xorsum=xorsum^arr[i];
    }
    return xorsum;
}
//q2
int setBit(int n,int pos){
    return ((n & (1<<pos))!=0);
}
void uniqueTwo(int arr[], int n){
    int xorsum =0;
    for(int i=0; i<n;i++){
        xorsum=xorsum^arr[i];
    }
    int tempxor = xorsum;
    int setbit=0;
    int pos=0;
    while(setbit!=1){
        setbit=xorsum&1;
        pos++;
        xorsum = xorsum>>1;
    }
    int newxor=0;
    for(int i=0;i<n;i++){
        if(setBit(arr[i],pos-1)){
            newxor=newxor^arr[i];
        }
    }

    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
}
