#include<iostream>
using namespace std;

bool areRotations(string a, string b){
    if (a.length() != b.length()) return false;
    return (a+a).find(b)!=string::npos;
}
int main(){
    string a = "avani";
    string b = "aniav";
    bool ans = areRotations(a,b);
    cout<<ans<<endl;
    return 0;
}