#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int checkPalindrome(string S);

int main(){
    string s = "AVANI";
    cout<<checkPalindrome(s)<<endl;
    string s1 = "Racecar";
    cout<<checkPalindrome(s1)<<endl;
    string s2 = "racecar";
    cout<<checkPalindrome(s2)<<endl;
    return 0;
}

int checkPalindrome(string S)
	{
	    int n = S.length();
	    for(int i=0; i<n/2; i++){
	        if(S[i]==S[n-1-i]){
	            continue;
	        }
	        else{
	            return 0;
	        }
	    }
	    return 1;
	}