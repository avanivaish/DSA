#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void cofactor(vector<vector<int>>& matrix, vector<vector<int>>& temp, int R, int C, int n)
    {
        int i = 0, j = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row != R && col != C)
                {
                    temp[i][j] = matrix[row][col];
                    j++;
                    if (j == n - 1)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

    // Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int>> matrix, int n)
    {
        // code here
        int ans = 0;
        if (n == 1)
            return matrix[0][0];

        vector<vector<int>> temp(n, vector<int>(n));
        int sign = 1;
        for (int i = 0; i < n; i++)
        {
            cofactor(matrix, temp, 0, i, n);
            ans += sign * matrix[0][i] * determinantOfMatrix(temp, n - 1);
            sign *= -1;
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // Example matrix
    vector<vector<int>> matrix = {
        {1,0,2,-1},
        {3,0,0,5},
        {2,1,4,-3},
        {1,0,5,0}};

    // Get the size of the matrix
    int n = matrix.size();

    // Calculate the determinant using the Solution class
    int determinant = solution.determinantOfMatrix(matrix, n);

    // Display the determinant
    cout << "Determinant of the matrix is: " << determinant << endl;

    return 0;
}
