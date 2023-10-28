/*
A B C 
B C D 
C D E 
*/
#include<iostream>
using namespace std;

int main(){
    int n = 3;
    for(int i=1;i<=n;i++){
        for(int j=i;j<i+3;j++){
            char c = 'A'+j-1;
            cout<<c<<" ";
        }cout<<endl;
    }
}