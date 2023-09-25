#include<iostream>
using namespace std;

int clearBit(int n,int pos);

int main(){
    int n = 5;
    int pos = 0;
    cout<<clearBit(n,pos)<<endl;
    return 0;
}

int clearBit(int n,int pos){
    int mask = ~(1<<pos);
    return n&mask;
}

