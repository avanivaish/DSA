//unique length 3
//palindromic subsequence
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int countPalindromicSubsequence(string s) {
    unordered_map<int, pair<int,int>> mp;
    for(char c='a'; c<='z'; c++){
        mp[c]={-1,-1};
    }
    int n = s.length();
    for(int i=0; i<n; i++){
        char c = s[i];
        if(mp[c].first==-1){
            mp[c].first=i;
        }
    }
    for(int i=n-1; i>=0; i--){
        char c = s[i];            
        if(mp[c].second==-1){
            mp[c].second=i;
        }
    }

    int ans = 0;
    for(auto p:mp){
        char c = p.first;
        int start = p.second.first;
        int end = p.second.second;
        unordered_set<int> st;
        for(int i=start+1; i<end; i++){
            st.insert(s[i]);
        }
        ans+=st.size();
    }
    return ans;
}
int main(){
    string a = "aabcdabca";
    int ans = countPalindromicSubsequence(a);
    cout<<ans<<endl;
    return 0;
}