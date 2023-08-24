#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k);

int main(){
    string s = "ABAB";
    int  k = 2;
    cout<<characterReplacement(s,k)<<endl;
    return 0;
}

int characterReplacement(string s, int k) {
    int n = s.size();
    int char_count[26] = {0};  
    int window_start = 0;
    int max_length = 0;
    int max_count = 0;  

    for (int window_end = 0; window_end < n; window_end++) {
        char_count[s[window_end] - 'A']++;  
        max_count = max(max_count, char_count[s[window_end] - 'A']); 
        
        if ((window_end - window_start + 1 - max_count) > k) {
            char_count[s[window_start] - 'A']--;  
            window_start++;  
        }
            
        // Update the maximum length of valid substring
        max_length = max(max_length, window_end - window_start + 1);
    }
    return max_length;
    }