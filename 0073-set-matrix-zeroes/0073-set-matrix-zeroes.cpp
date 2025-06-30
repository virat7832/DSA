class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();        // Number of rows
        int m = matrix[0].size();     // Number of columns
        int col0 = 1;                 // Flag for the first column

        // Step 1: Mark the rows and columns to be set to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the ith row
                    if (j != 0)
                        matrix[0][j] = 0; // Mark the jth column
                    else
                        col0 = 0; // Mark the first column separately
                }
            }
        }

        // Step 2: Use the marks to set matrix elements to 0 (excluding first row and column)
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle the first row
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle the first column
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};