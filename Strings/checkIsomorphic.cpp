//CHECK ISOMORPHIC 
#include<iostream>
using namespace std;

bool isIsomorphic(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    if(n!=m){
        return false;
    }
    
    int map1[256]={0};
    int map2[256]={0};
    for (int i=0;i<m;i++){
        if(!map1[s1[i]] && !map2[s2[i]]){
            map1[s1[i]]=s2[i];
            map2[s2[i]]=s1[i];
        }else if(map1[s1[i]]!=s2[i]){
            return false;
        }
    }
    return true;
}
int main(){
    string s1 = "aab";
    string s2 = "xxy";
    bool ansS12 = isIsomorphic(s1,s2);
    cout<<"String 1: "<<s1<<endl;
    cout<<"String 2: "<<s2<<endl;
    cout<<"Ans: "<<ansS12<<endl;

    string s3 = "abcd";
    string s4 = "fgss";
    bool ansS34 = isIsomorphic(s3,s4);
    cout<<"String 1: "<<s3<<endl;
    cout<<"String 2: "<<s4<<endl;
    cout<<"Ans: "<<ansS34<<endl;

    return 0;
}