#include<iostream>
#include<unordered_map>
using namespace std;

bool isVowel(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

string sortVowels(string s){
    unordered_map<char,int> count;
    for(auto c : s){
        if(isVowel(c)){
            count[c]++;
        }
    }
    string reqVowels = "aeiou";
    string ans = "";
    int j = 0;
    for(int i = 0; i < s.length(); i++){
        if(isVowel(s[i])){
            while(count[reqVowels[j]] == 0){
                j++;
            }
            ans += reqVowels[j];
            count[reqVowels[j]]--;
        }
        else {
            ans += s[i]; // Append non-vowel characters directly
        }
    }
    return ans;
}

int main(){
    string s = "avanivaish";
    string ans = sortVowels(s);
    cout << ans << endl;
    return 0;
}
