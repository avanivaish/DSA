#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int m = 3;
    int n = 3;
    int matrix[m][n] = {{1,1,1},{1,0,1},{1,1,1}};

    //int m = 3;
    //int n = 4;
    //int matrix[m][n]= {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i=1; i<m; i++){
        if(matrix[i][0]==0){
            for(int j=1; j<n; j++){
                matrix[i][j]=0;
            }
        }
    }

    for(int j=1; j<n; j++){
        if(matrix[0][j]==0){
            for(int i=1; i<m; i++){
                matrix[i][j]=0;
            }
        }
    }

    //matrix[0,0] special codition to be checked at the end..
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[0][0]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }

    //return matrix
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}