#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

bool validParenthesisString(string s);

int main(){
    string s = "()";
    bool ans = validParenthesisString(s);
    cout<<ans<<endl;
    string s1 = "()[";
    bool ans1 = validParenthesisString(s1);
    cout<<ans1<<endl;
    string s2 = "*";
    bool ans2 = validParenthesisString(s2);
    cout<<ans2<<endl;
    return 0;
}

bool validParenthesisString(string s){
    int n = s.length();
    stack<int> open,star;
    for(int i=0; s[i]!='\0'; ++i){
        if(s[i]=='('){
            open.push(i);
        }
        else if(s[i]=='*'){
            star.push(i);
        }
        else{
            if(!open.empty()){
                open.pop();
            }
            else if(!star.empty()){
                star.pop();
            }
            else{
                return false;
            }
        }
    }

    while(!open.empty()){
        if(star.empty()){
            return false;
        }
        else if(open.top()<star.top()){
            open.pop();
            star.pop();
        }
        else{
            return false;
        }
    }
    return true;
}