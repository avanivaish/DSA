#include<iostream>
using namespace std;

bool rotateString2Places(string s1, string s2){
    int n = s1.length();
    if(n==2){
        return true;
    }
    for(int i=0; i<n; i++){
        if(s1[(i+2)%n]==s2[i] || s1[(n+i-2)%n]==s2[i]){
            continue;
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    string a = "avani";
    string b =  "niava";
    bool ans = rotateString2Places(a,b);
    cout<<ans<<endl;
    return 0;
}