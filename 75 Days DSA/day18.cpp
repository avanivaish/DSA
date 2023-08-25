#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool checkValidAnagram(string s, string t);

int main(){
    string s = "anagram";
    string t = "nagaram";

    string s1 = "car";
    string t1 = "rat";

    cout<<checkValidAnagram(s,t)<<endl;
    cout<<checkValidAnagram(s1,t1)<<endl;
    return 0;
}

bool checkValidAnagram(string s, string t){
    if(s.size()!=t.size()){
        return false;
    }
    int arr[26] = {0};
    for(int i=0; i<s.size(); i++){
        arr[s[i]-'a']++;
    }
    for(int j=0; j<t.size(); j++){
        arr[t[j]-'a']--;
    }

    for(int c=0; c<26; c++){
        if(arr[c]!=0){
            return false;
        }
    }
    return true;
}