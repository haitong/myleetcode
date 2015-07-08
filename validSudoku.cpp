/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int valid = 0;
        for(auto row : board){
            valid = 0;
            for(auto c : row){
                if(c == '.') continue;
                if(c < '0' || c > '9') return false;
                if(valid & (1 << (int)(c - '0'))) return false;
                valid |= 1 << (int)(c - '0');
            }
        }
        for(int col = 0; col < board[0].size(); col++){
            valid = 0;
            for(int row = 0; row < board.size(); row++){
                if(board[row][col] == '.') continue;
                if(board[row][col] < '0' || board[row][col] > '9') return false;
                if(valid & (1 << (int)(board[row][col] - '0'))) return false;
                valid |= 1 << (int)(board[row][col] - '0');
            }
        }
        
        for(int i = 0; i < 3; i ++){
            for(int j = 0; j < 3; j ++){
                valid = 0;
                for(int row = i * 3; row < (i+1)*3; row++){
                    for(int col = j * 3; col < (j+1)*3; col++){
                        if(board[row][col] == '.') continue;
                        if(board[row][col] < '0' || board[row][col] > '9') return false;
                        if(valid & (1 << (int)(board[row][col] - '0'))) return false;
                        valid |= 1 << (int)(board[row][col] - '0');                        
                    }
                }
            }
        }
        return true;
    }
};
