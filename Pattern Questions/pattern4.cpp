/*
333
222
111
*/

#include<iostream>
using namespace std;
int main() {
    int n = 3;
    for(int i=n;i>=1;i--){
        for(int j=1; j<=n; j++){
            cout<<i;
        }cout<<endl;
    }
    return 0;
}