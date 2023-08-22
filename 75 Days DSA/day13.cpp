#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 3;
    int matrix[n][n] = {{1,2,3},{4,5,6},{7,8,9}};

    //transpose 
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reverse rows using vectors
    for(int i=0; i<n; i++){
        vector<int> rowVec(matrix[i], matrix[i] + n);  // Convert row to vector
        reverse(rowVec.begin(), rowVec.end());
        for(int j=0; j<n; j++){
            matrix[i][j] = rowVec[j];  // Copy elements back to the row
        }
    }


    //rotated matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}