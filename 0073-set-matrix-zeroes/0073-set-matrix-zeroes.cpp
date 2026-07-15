class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> zeroRows;
        vector<int> zeroCols;
        // First pass - store all the rows and columns having zero
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) {
                    zeroRows.push_back(row);
                    zeroCols.push_back(col);
                }
            }
        }
        // Second pass - change the row to zero
        for (int row : zeroRows) {
            for (int col = 0; col < cols; col++) {
                matrix[row][col] = 0;
            }
        }
        // Third pass - change the column to zero
        for (int col : zeroCols) {
            for (int row = 0; row < rows; row++) {
                matrix[row][col] = 0;
            }
        }
    }
};