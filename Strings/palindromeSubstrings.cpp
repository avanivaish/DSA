#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int palindromeSubstringCount(string s);
int palindromeSubstringCountMoreThanTwo(string s);

int main(){
    string s ="abc";
    cout<<palindromeSubstringCount(s)<<endl;
    string s1 ="aaaaa";
    cout<<palindromeSubstringCount(s1)<<endl;
    cout<<palindromeSubstringCountMoreThanTwo(s1)<<endl;

    return 0;
}

int  palindromeSubstringCount(string s){
    int n = s.size();
    int count = 0;
    vector<vector<bool>> dp(n,vector<bool>(n,false));

    for(int diff=0; diff<n; diff++){
        for(int i=0, j=i+diff; j<n; i++, j++){
            if(diff==0){
                dp[i][j]=true;
            }
            else if(diff==1){
                if(s[i]==s[j]){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j]=false;
                }
            }
            else{
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                else{
                    dp[i][j]=false;
                }
            }

            if(dp[i][j]==true){
                count++;
            }
        }
    }
    return count;
}

int  palindromeSubstringCountMoreThanTwo(string s){
    int n = s.size();
    int count = 0;
    vector<vector<bool>> dp(n,vector<bool>(n,false));

    for(int diff=0; diff<n; diff++){
        for(int i=0, j=i+diff; j<n; i++, j++){
            if(diff==0){
                dp[i][j]=true;
            }
            else if(diff==1){
                if(s[i]==s[j]){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j]=false;
                }
            }
            else{
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                else{
                    dp[i][j]=false;
                }
            }

            if(dp[i][j]==true && i!=j){
                count++;
            }
        }
    }
    return count;
}
