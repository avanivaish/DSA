#include<iostream>
using namespace std;

int getBit(int n,int pos);

int main(){
    int n = 5;
    int pos = 3;
    cout<<getBit(n,pos)<<endl;
    return 0;
}

int getBit(int n,int pos){
    return ((n&(1<<pos))!=0);
}

