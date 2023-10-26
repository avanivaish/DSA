/*
D 
C D 
B C D 
A B C D 
*/
#include<iostream>
using namespace std;

int main(){
    int n = 4;
    for(int i=4;i>=1; i--){
        for(int j=i; j<=4; j++){
            char c = 'A'+j-1;
            cout<<c<<" ";
        }cout<<endl;
    }
}