/*
A 
B B 
C C C 
*/
#include<iostream>
using namespace std;
int main(){
    int n = 3;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            char c = 'A'+i-1;
            cout<<c<<" ";
        }cout<<endl;
    }
}