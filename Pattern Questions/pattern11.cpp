/*
Hello, World!
A B C D 
A B C D 
A B C D 
A B C D 
*/
#include<iostream>
using namespace  std;

int main(){
    int n = 4;
    cout<<"Hello, World!"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c = 'A'+j-1;
            cout<<c<<" ";
        }cout<<endl;
    }
}