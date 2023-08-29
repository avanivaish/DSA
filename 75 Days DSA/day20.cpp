#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool valid(string s);

int main(){
    string s = "(){}[]";  //true
    string s1 = "()";
    bool ans = valid(s);
    cout<<ans<<endl;
    bool ans1 = valid(s1);
    cout<<ans1<<endl;

    return 0;
}

bool valid(string s){
    stack<int> st;
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                return false;
            }
            char c = st.top();
            st.pop();
            if ((s[i]==')' && c=='(') || (s[i]==']' && c=='[') || (s[i]=='}' && c=='{')){
                continue;
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}