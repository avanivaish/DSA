#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<vector<string>> groupAnagram(vector<string>& strs);

int main() {
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagram(str);

    for (const auto& group : result) {
        cout << "[";
        for (const string& word : group) {
            cout << "\"" << word << "\", ";
        }
        cout << "], ";
    }

    return 0;
}


vector<vector<string>> groupAnagram(vector<string>& strs){
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> mp;
    for(auto str:strs){
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }
    for(auto x:mp){
        ans.push_back(x.second);
    }
    return ans;
}
