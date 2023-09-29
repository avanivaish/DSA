#include<iostream>
using namespace std;

int setBit(int n,int pos);

int main(){
    int n = 5;
    int pos = 1;
    cout<<setBit(n,pos)<<endl;
    return 0;
}

int setBit(int n,int pos){
    return (n|(1<<pos));
}

