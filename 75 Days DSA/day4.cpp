#include<iostream>
using namespace std;

int main(){
    int n = 5;
    int nums[n] = {1,2,3,4,5};
    int left[n], result[n];

    //left array
    left[0]=nums[0];
    for(int i=1; i<n; i++){
        left[i]=nums[i-1]*nums[i];
    }

    //prd variable 
    int prd = nums[n-1];
    
    //result array
    result[n-1]=left[n-2];
    for(int i=n-2; i>0; i--){
        result[i]=prd*left[i-1];
        prd = prd * nums[i];
    }
    result[0]=prd;

    //printing output array - result
    for(int j=0; j<n; j++){
        cout<<result[j]<<" ";
    }
    cout<<endl;
    return 0;
}