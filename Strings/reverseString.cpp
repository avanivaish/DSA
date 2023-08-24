#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string reverseString(string s);

int main(){
    string s = "HelloWorld";
    cout<<reverseString(s)<<endl;
    string s1 = "STRING";
    cout<<reverseString(s1)<<endl;
}

string reverseString(string s){
    int n = s.length();
    for(int i=0; i<n/2; i++){
        //swaping
        char temp = s[i];
        s[i]=s[n-1-i];
        s[n-1-i]=temp;
    }
    return s;
}
