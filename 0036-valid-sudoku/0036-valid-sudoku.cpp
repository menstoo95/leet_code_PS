class Solution {
public:
    bool row(vector<vector<char>>& board, int r, int c){
        vector<bool> checker(10);
        
        for(int i = 0; i < 9; i++){
            if(board[r][i] != '.'){
                if(checker[(int)board[r][i]])
                    return false;
                else
                    checker[(int)board[r][i]] = true;
            }
        }
        return true;
    }
    
    bool col(vector<vector<char>>& board, int r, int c){
        vector<bool> checker(10);
        
        for(int i = 0; i < 9; i++){
            if(board[i][c] != '.'){
                if(checker[(int)board[i][c]])
                    return false;
                else
                    checker[(int)board[i][c]] = true;
            }
        }
        return true;
    }
    
    bool square(vector<vector<char>>& board, int r, int c){
        int rpart = (r/3);
        int cpart = (c/3);
        vector<bool> checker(10);

        for(int i = rpart*3; i < rpart*3+3; i++){
            for(int j = cpart*3; j < cpart*3+3; j++){
                if(board[i][j] != '.'){
                    if(checker[(int)board[i][j]])
                        return false;
                    else
                        checker[(int)board[i][j]] = true;
                }
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(!col(board,i,j) || !row(board,i,j) || !square(board, i, j))
                        return false;
                }
            }
        }
        return true;
    }
};