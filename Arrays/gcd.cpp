//GCD: GREATEST COMMON DIVISOR  ----- EUCLID ALGORITHM 
//ex: 42 and 24 - gcd is 6
/*gcd of 42-24 is equal to gcd of 24-18 is equal to 18-6 ...and so onnnnn */

#include<iostream>
using namespace std;
int gcd(int a, int b);
int main(){
    int a = 42, b = 24;
    cout<<gcd(a,b)<<endl;
}

int gcd(int a,int b){
    while(b!=0){
        int rem = a%b;
        a=b;
        b=rem;
    }
    return a;
}