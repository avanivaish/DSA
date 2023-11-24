#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1; col<row; col++){
        ans = ans*(row-col);
        ans = ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle(int N){
    vector<vector<int>> ans;
    for(int i=1; i<N; i++){
        vector<int> temp = generateRow(i);
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    int N = 6;
    vector<vector<int>> pascal = pascalTriangle(N);
    for(auto it : pascal){
        for(auto el: it){
            cout<<el<<" ";
        }cout<<endl;
    }
    return 0;
}
