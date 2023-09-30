#include<iostream>
using namespace std;
bool powerOfTwo(int n);
int main(){
    int n = 16;
    cout<<powerOfTwo(n)<<endl;
    return 0;
}

bool powerOfTwo(int n){
    return (n && !(n & n-1));
}