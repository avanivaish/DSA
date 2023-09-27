//COUNT THE NUMBER OF ONES IN A BINARY REPRESENTATION OF A NUMBER
#include<iostream>
using namespace std;
int numberofOnes(int n);
int main(){
    int n = 19;
    cout<<numberofOnes(n)<<endl;
    return 0;
}
int numberofOnes(int n){
    int count=0;
    while(n!=0){
        n = n & (n-1);
        count++;
    }
    return count;
}

