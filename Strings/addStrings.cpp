#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2);
string addStrings1(string num1, string num2);

int main(){
    string num1 = "123";
    string num2 ="11";
    string str = addStrings1(num2,num1);
    string num3 = "456";
    string num4 = "77";
    string str1 = addStrings1(num3,num4);
    cout<<str<<endl;
    cout<<str1<<endl;
    return 0;
}

string addStrings(string num1, string num2){
    int n1 = num1.length()-1;
    int n2 = num2.length()-1;

    int carry=0;
    string ans="";

    while(n1>=0|| n2>=0){
        if(n1<0){
            ans.push_back(((num2[n2]-48 + carry)%10)+48);
            carry = (num2[n2]-48 + carry)/10;
            n2--;
        }
        else if(n2<0){
            ans.push_back(((num1[n1]-48 + carry)%10)+48);
            carry = (num1[n1]-48 + carry)/10;
            n1--;
        }
        else{
            ans.push_back(((num1[n1]-48 + num2[n2]-48 + carry)%10)+48);
            carry = (num1[n1]-48 + num2[n2]-48 + carry)/10;
            n1--; 
            n2--;
        }

        if(carry){
            ans.push_back(carry+48);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string addStrings1(string num1, string num2){
    int n1 = num1.length() - 1;
    int n2 = num2.length() - 1;
    int carry = 0;
    string ans = "";

    while (n1 >= 0 || n2 >= 0) {
        int digitSum = carry;

        if (n1 >= 0) {
            digitSum += num1[n1] - '0';
            n1--;
        }
        if (n2 >= 0) {
            digitSum += num2[n2] - '0';
            n2--;
        }

        ans.push_back((digitSum % 10) + '0');
        carry = digitSum / 10;
    }

    if (carry) {
        ans.push_back(carry + '0');
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
