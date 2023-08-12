#include<iostream>
using namespace std;

int main(){
    //int n = 6;
    //int prices[6]={7,1,5,3,6,4};
    int n;
    cout<<"Enter length of price array: ";
    cin>>n;
    int prices[n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; i++){
        cin>>prices[i];
    }
    
    int profit = 0;
    int buy = prices[0];
    int max_price = 0;
    for(int i=1; i<n; i++){
        if (prices[i]<buy){
            buy = prices[i];
        }
        else{
            profit = prices[i]-buy;
            max_price = max(profit, max_price);
        }
    }
    cout<<"Profit: "<<max_price<<endl;
    return 0;
}