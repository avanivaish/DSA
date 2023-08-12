//KADANE ALGORITHM
#include<iostream>
#include<climits>
using namespace std;

int main(){
    //int n = 9;
    //int nums[9] = {-2,1,-3,4,-1,2,1,-5,4};

    //int n=1;
    //int nums[n]={1};

    int n;
    cin>>n;
    int nums[n];
    for (int i=0; i<n; i++){
        cin>>nums[i];
    }
    
    int maxsum = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + nums[i];
        maxsum = max(sum,maxsum);
        if(sum <0){
            sum = 0;
            //maxsum = max(sum,maxsum);
        }
        else{
            maxsum = max(sum,maxsum);
        }
    }
    cout<<maxsum<<endl;
    return 0;
}
