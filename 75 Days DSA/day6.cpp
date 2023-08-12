#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n = 6;
    int nums[n] = {2,0,3,-6,4,1};

    //int n = 3;
    //int nums[n]={-2,0,-1};

    int maxprd =1;
    int prd =1;

    for (int i=0; i<n; i++){
        prd = prd * nums[i];
        if(prd<1){
            prd = 1;
            maxprd = max(maxprd,prd);
        }
        else{
            maxprd = max(maxprd,prd);
        }
    }
    if(maxprd==1){
        maxprd = 0;
    }
    cout<<maxprd;
    return 0;
}


/*



*/