#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        int i=0;
        while(i<s.length() && s[i]==' '){
            i++;
        }
        s=s.substr(i);
        int sign = +1;
        long ans = 0;
        if(s[0]=='-') sign = -1;
        int max = INT_MAX, min = INT_MIN;
        i = (s[0]=='+' || s[0]=='-') ? 1:0;
        while(i<s.length()){
            if(s[i]==' ' || !isdigit(s[i])) break;
            ans = ans * 10 + (s[i]-'0');
            if(sign == -1 && -1*ans < min) return min;
            if(sign == +1 && ans > max) return max;
            i++;
        }
        return (int)(sign*ans);
    }
};

int main() {
    Solution solution;
    
    // Test cases
    string test1 = "42";
    string test2 = "   -42";
    string test3 = "4193 with words";
    string test4 = "words and 987";
    
    cout << "Test 1: " << solution.myAtoi(test1) << endl;
    cout << "Test 2: " << solution.myAtoi(test2) << endl;
    cout << "Test 3: " << solution.myAtoi(test3) << endl;
    cout << "Test 4: " << solution.myAtoi(test4) << endl;

    return 0;
}
