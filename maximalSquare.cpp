/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/
class Solution {
public:
    bool square(vector<vector<char>>& matrix, int row, int col, int width){
        for(int i = row; i < row + width; i ++){
            for(int j = col; j < col + width; j ++){
                if(matrix[i][j] == '0') return false;
            }
        }
        return  true;
    }
    
    void bestMatrix(int & res, vector<vector<char>>& matrix, int row, int col){
        if(matrix[row][col] == '0') return;
        while(row + res + 1 <= matrix.size() && col + res + 1 <= matrix[0].size()){
            if(square(matrix, row, col, res + 1)){
                res ++;
            }
            else break;
        }
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        if(matrix.empty() || matrix[0].empty()) return res;
        for(int i = 0; i < matrix.size(); i ++){
            for(int j=0; j < matrix[0].size(); j ++){
                bestMatrix(res, matrix, i, j);
            }
        }
        return res*res;
    }
};
