#include<iostream>
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main(){
    int n = 4;
    int nums[n] = {1,2,3,1};
    unordered_map<int,int> freq;
    for(int i=0; i<n; i++){
        freq[nums[i]]++;
    }
    bool ans = false;
    for(auto x:freq){
        if (x.second > 1){
            ans = true;
            break;
        }
    }
    //cout<<ans;
    cout << (ans ? "true" : "false"); 
    return 0;
}