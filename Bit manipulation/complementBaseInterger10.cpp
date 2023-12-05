#include <iostream>

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }

        int m = n;
        int mask = 0;

        while (m != 0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }

        int ans = (~n) & mask;
        return ans;
    }
};

int main() {
    using namespace std;

    Solution solution;

    // Test cases
    cout << "Complement of 5: " << solution.bitwiseComplement(5) << endl;
    cout << "Complement of 10: " << solution.bitwiseComplement(10) << endl;
    cout << "Complement of 0: " << solution.bitwiseComplement(0) << endl;

    return 0;
}
