class Solution {
public:
    void transpose_square_matrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void reverse_all_rows(vector<vector<int>> &matrix) {
        int m = matrix[0].size();
        for(auto &row: matrix) {
            for(int j=0; j<m/2; j++) {
                swap(row[j], row[m-j-1]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        // rotate clockwise -> transpose then reverse_all_rows
        // rotate anticlockwise -> reverse_all_rows then transpose
        transpose_square_matrix(matrix);
        reverse_all_rows(matrix);
    }
};