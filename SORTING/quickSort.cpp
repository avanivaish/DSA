#include<iostream>
using namespace std;

void quickSort(int arr[], int s, int e);
int partition(int arr[], int s, int e);

int main(){
    int n = 7;
    int arr[n]={105,9,313,35,55,58,12};
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void quickSort(int arr[], int s, int e){
    if(s>=e){return;}
    int p = partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int partition(int arr[],int s, int e){
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot){count++;}
    }

    //place pivot in right place
    int pivotindex = s+count;
    swap(arr[pivotindex],arr[s]);

    //left and right part of pivot element
    int i=s, j=e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<pivot){i++;}
        while(arr[j]>pivot){j--;}
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}
