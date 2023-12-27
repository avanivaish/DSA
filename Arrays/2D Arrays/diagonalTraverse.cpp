#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        map<int, vector<int>> mp;
        vector<int> result;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for(auto &it:mp){
            if(flip){
                reverse(it.second.begin(), it.second.end());
            }
            for(int &num: it.second){
                result.push_back(num);
            }
            flip = !flip;
        }
        return result;
    }
};

int main() {
    // Example usage
    Solution solution;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> diagonalOrder = solution.findDiagonalOrder(matrix);

    cout << "Diagonal Order: ";
    for(int num : diagonalOrder) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
