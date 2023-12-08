#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        for(int j = 1, count = 1; j <= chars.size(); j++, count++){
            if(j == chars.size() || chars[j - 1] != chars[j]){
                chars[i] = chars[j - 1];
                i++;
                if(count > 1){
                    for(char digit: to_string(count)){
                        chars[i] = digit;
                        i++;
                    }
                }
                count = 0;
            }
        }
        return i;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<char> input = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    
    int compressedLength = solution.compress(input);
    
    cout << "Compressed characters: ";
    for (int i = 0; i < compressedLength; ++i) {
        cout << input[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}
