#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s);

int main(){
    string s = "abcabcbb";
    string s1 = "bbbbbb";
    cout<<lengthOfLongestSubstring(s1)<<endl;
}

int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_map<int,int> mp;
        int ans = INT_MIN;

        while(j<s.size()){
            if(mp.find(s[j])==mp.end()){
                ans = max(ans, j-i+1);
                mp[s[j]] = j;
            }
            else{
                int index = mp[s[j]];
                while(i<=index){
                    mp.erase(s[i]);
                    i++;
                }
                mp[s[j]]=j;
            }
            j++;
        }
        if(ans == INT_MIN){
            return 0;
        }
        return ans;
    }
