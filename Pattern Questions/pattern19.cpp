/*
****
 ***
  **
   *
*/
#include<iostream>
using namespace std;

int main(){
    int n= 4;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i-1;j++){
            cout<<" ";
        }
        for(int k=i-1; k<n;k++){
            cout<<"*";
        }
        cout<<endl;
    }
}