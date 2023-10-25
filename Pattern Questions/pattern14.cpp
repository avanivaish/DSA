/*
A 
B C 
D E F 
G H I J 
K L M N O 
*/
#include<iostream>
using namespace std;
int main(){
    int n = 5;
    int count= 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            char c = 'A'+count-1;
            cout<<c<<" ";
            count++;
        }cout<<endl;
    }
}