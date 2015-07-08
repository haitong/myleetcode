/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/
class Solution {
public:
    void setup(vector<int> & rows, vector<int> & cols, vector<vector<int>> & matrix, vector<vector<char>>& board){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int row = i * 3; row < (i+1)*3; row++){
                    for(int col = j * 3; col < (j+1)*3; col++){
                        if(board[row][col] != '.'){
                            matrix[i][j] |= (1 << (board[row][col] - '1'));
                        }
                    }
                }
            }
        }
        
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] != '.'){
                    rows[row] |= (1 << (board[row][col] - '1'));
                }
            }
        }

        for(int col = 0; col < 9; col++){
            for(int row = 0; row < 9; row++){
                if(board[row][col] != '.'){
                    cols[col] |= (1 << (board[row][col] - '1'));
                }
            }
        }        
        
    }
    
    inline bool valid(int v, char c){
        return  !(v & (1 << (c-'1')));
    }
    
    inline void set(int & t, char c){
        t |= (1 << (c - '1'));
    }
    
    inline void unset(int & t, char c){
        t ^= (1 << (c - '1'));
    }
    
    bool solve(vector<int> & rows, vector<int> & cols, vector<vector<int>> & matrix, vector<vector<char>>& board, int index){
        if(index > 80) return true;
        int row = index/9;
        int col = index%9;
        while(board[row][col] != '.'){
            index++;
            if(index > 80) return true;
            row = index/9;
            col = index%9;
        }
        
        int m_row = row/3;
        int m_col = col/3;
        
        for(char c = '1'; c <= '9'; c++){
            if(valid(rows[row],c) && valid(cols[col],c) && valid(matrix[m_row][m_col],c)){
                board[row][col] = c;
                set(rows[row],c);
                set(cols[col],c);
                set(matrix[m_row][m_col],c);
                if(solve(rows, cols, matrix, board, index+1)) return true;
                unset(rows[row],c);
                unset(cols[col],c);
                unset(matrix[m_row][m_col],c); 
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> rows(9,0), cols(9,0);
        vector<vector<int>> matrix(3, vector<int>(3,0));
        setup(rows, cols, matrix, board);
        solve(rows, cols, matrix, board, 0);
    }
};
