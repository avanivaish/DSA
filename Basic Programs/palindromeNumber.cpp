#include<iostream>
using namespace std;

bool checkPalindromeNumber(int x){
    if(x<0){
        return false;
    }
    int reverse = 0, temp = x;
    while (temp > 0) {
        int digit = temp % 10;
        reverse = reverse * 10 + digit;
        temp = temp / 10;
    }

    if(reverse==x){
        return true;
    }else{
        return false;
    }
}

int main(){
    int num1 = 121;
    bool res1 = checkPalindromeNumber(num1);
    cout<<num1<<" : "<< res1<<endl;

    int num2 = 1009;
    bool res2 = checkPalindromeNumber(num2);
    cout<<num2<<" : "<< res2<<endl;

    return 0;
}