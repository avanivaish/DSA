#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool valid(string s);

int main(){
    string s = "(){}[]";  //true
    string s1 = "](){}[]";  //false
    string s2 = "(){[]}"; //true
    string s3 = "()}[])";  //false
    bool ans = valid(s);
    cout<<ans<<endl;
    bool ans1 = valid(s1);
    cout<<ans1<<endl;
    bool ans2 = valid(s2);
    cout<<ans2<<endl;
    bool ans3 = valid(s3);
    cout<<ans3<<endl;

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