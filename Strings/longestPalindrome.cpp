#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s);

int main(){
    string s = "aabaa";
    cout<<longestPalindrome(s)<<endl;
    string s1 = "babad";
    cout<<longestPalindrome(s1)<<endl;
}

string longestPalindrome(string s){
    int n = s.size();
    string ans;
    int maxlen=0;
    vector<vector<int>> dp(n,vector<int>(n,0));
        
    for(int diff=0; diff<n; diff++){
        for(int i=0, j=i+diff; j<n; i++, j++){
            if(i==j){
                dp[i][j]=1;
            }
            else if(diff==1){
                if(s[i]==s[j]){
                    dp[i][j]=2;
                }
                else{
                    dp[i][j]=0;
                }
            }
            else{
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }
            }
                
            if(dp[i][j]){
                if(j-i+1>maxlen){
                    maxlen = j-i+1;
                    ans = s.substr(i,maxlen);
                }
            }
        }
    }
return ans;
}