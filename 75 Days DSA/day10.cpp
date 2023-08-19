#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n = 9;
    int height[n] = {1,8,6,2,5,6,8,3,7} ;

    int start = 0;
    int end = n-1;

    int area = 0;
    int maxarea = 0;

    while(start<end){
        area = (min(height[start],height[end])) * (end-start);
        maxarea = max(area,maxarea);
        if(height[start]<height[end]){
            start++;
        }
        else{
            end--;
        }
    }
    cout<<maxarea<<endl;
}