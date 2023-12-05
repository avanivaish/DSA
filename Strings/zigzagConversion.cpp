#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);
        if(numRows==1) return s;
        bool flag = false;
        int i=0;
        for(auto ch: s){
            ans[i] += ch;
            if(i==0 || i==numRows-1){
                flag = !flag;
            }
            if(flag){
                i+=1;
            }else{
                i-=1;
            }
        }
        string zigzag = "";
        for(auto str: ans){
            zigzag += str;
        }
        return zigzag;
    }
};
int main() {
    Solution solution;

    // Example 1
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << "Example 1: " << solution.convert(s1, numRows1) << endl;
    // Output should be "PAHNAPLSIIGYIR"

    // Example 2
    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << "Example 2: " << solution.convert(s2, numRows2) << endl;
    // Output should be "PINALSIGYAHRPI"

    return 0;
}
