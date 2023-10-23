/*
Hello, World!
A B C D 
E F G H 
I J K L 
M N O P 
*/
#include<iostream>
using namespace  std;

int main(){
    int n = 4;
    int count = 1;
    cout<<"Hello, World!"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c = 'A'+count-1;
            cout<<c<<" ";
            count++;
        }cout<<endl;
    }
}