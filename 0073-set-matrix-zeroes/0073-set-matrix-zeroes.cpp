// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int rows = matrix.size();
//         int cols = matrix[0].size();
//         vector<int> zeroRows;
//         vector<int> zeroCols;
//         // First pass - store all the rows and columns having zero
//         for (int row = 0; row < rows; row++) {
//             for (int col = 0; col < cols; col++) {
//                 if (matrix[row][col] == 0) {
//                     zeroRows.push_back(row);
//                     zeroCols.push_back(col);
//                 }
//             }
//         }
//         // Second pass - change the row to zero
//         for (int row : zeroRows) {
//             for (int col = 0; col < cols; col++) {
//                 matrix[row][col] = 0;
//             }
//         }
//         // Third pass - change the column to zero
//         for (int col : zeroCols) {
//             for (int row = 0; row < rows; row++) {
//                 matrix[row][col] = 0;
//             }
//         }
//     }
// };

// OPTIMIZED SOLUTION
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<bool> zeroRow(rows, false);
        vector<bool> zeroCol(cols, false);

        // Mark rows and columns
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    zeroRow[i] = true;
                    zeroCol[j] = true;
                }
            }
        }

        // Set zeros in rows and columns where condition is True
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (zeroRow[i] || zeroCol[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};