#include<iostream>
#include<queue>
using namespace std;

bool rotateString(string a, string b){
    int n = a.length();
    if(a==b){
        return true;
    }
    if(a.length()!=b.length()){
        return false;
    }

    queue<char> q1,q2;
    for(int i=0; i<n; i++){
        q1.push(a[i]);
    }
    for(int i=0; i<n; i++){
        q2.push(b[i]);
    }

    int k = q2.size()-1;
    while(k!=0){
        char c = q2.front();
        q2.pop();
        q2.push(c);
        if(q1==q2){
            return true;
        }
        k--;
    }
    return false;
}
int main(){
    string a = "avani";
    string b =  "iavan";
    bool ans = rotateString(a,b);
    cout<<ans<<endl;
    return 0;
}