#include <iostream>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.length() - 1; i >= 0; --i) {
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main() {
    Solution solution;

    // Example usage:
    string input = "123456";
    string result = solution.largestOddNumber(input);

    // Display the result
    cout << "Largest Odd Number: " << result << endl;

    return 0;
}
