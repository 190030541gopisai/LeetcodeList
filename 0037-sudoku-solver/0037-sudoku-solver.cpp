class Solution {
    bool isValid(int i, int j, char ch, vector<vector<char>> &board){
        if(i < 0 || j < 0 || i >= 9 || j >= 9){
            return false;
        }
        // vertical
        for(int p = 0; p < 9; p++){
            if(board[p][j] == ch){
                return false;
            }
        }
        
        //horizontal
        for(int q = 0; q < 9; q++){
            if(board[i][q] == ch){
                return false;
            }
        }
        
        // 4, 6 ==> (3, 6)
        // 4/3 = 1 * 3 = 3
        // 6/3 = 2 * 3 = 6
        int startrow = 3 * (i / 3); 
        int startcol = 3 * (j / 3); 
        
        for(int p = startrow; p < startrow + 3; p++){
            for(int q = startcol; q < startcol + 3; q++){
                if(board[p][q] == ch){
                    return false;
                }
            }
        }
        
        return true;
    }
    bool solveSudokuHelper(vector<vector<char>> &board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] ==  '.'){
                    for(int k = 1; k <= 9; k++){
                        char ch = '0' + k;
                        if(isValid(i, j, ch, board)){
                            board[i][j] = ch;
                            if(solveSudokuHelper(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);
    }
};