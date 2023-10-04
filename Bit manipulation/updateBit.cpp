#include<iostream>
using namespace std;

int updateBit(int n,int i, int val);

int main(){
    int n=5;
    int i=1;
    int val=1;
    cout<<updateBit(n,i,val)<<endl;
    return 0;
}

int updateBit(int n, int i, int val){
    //clearbit
    int mask = ~(1<<i);
    n = n & mask;
    //setbit
    return(n | (val<<i));
}

