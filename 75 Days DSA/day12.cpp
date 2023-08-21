#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
   
    int m = 3;
    int n = 3;
    int matrix[m][n]={{1,2,3},{4,5,6},{7,8,9}};
    
    /*
    int m = 3;
    int n = 4;
    int matrix[m][n] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    */

    vector<int> result;

    int row_start = 0;
    int row_end = m-1;
    int col_start = 0;
    int col_end = n-1;

    while(row_start<=row_end && col_start<=col_end){
        //traverse first row
        for(int col=col_start; col<=col_end; col++){
            result.push_back(matrix[row_start][col]);
        }
        row_start++;

        //traverse last col
        for(int row=row_start; row<=row_end; row++){
            result.push_back(matrix[row][col_end]);
        }
        col_end--;

        if(row_start<=row_end){
            //traverse last row
            for(int col=col_end; col>=col_start; col--){
                result.push_back(matrix[row_end][col]);
            }
            row_end--;
        }

        if(col_start<=col_end){
            //traverse first col
            for(int row=row_end; row>=row_start; row--){
                result.push_back(matrix[row][col_start]);
            }
            col_start++;
        }
    }

    //return result[]
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}