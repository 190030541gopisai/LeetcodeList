#include<iostream>
#include<vector>

using namespace std;

bool isValid(int row, int col, int N, char ch, vector<vector<char>> &board){
	// checking column wise
	for(int i = 0; i < 9; i++){
		if(board[row][i] == ch){
			return false;
		}
		if(board[i][col] == ch){
			return false;
		}
	}

	// checking in sub 3 x 3 matrix
	
	int startrow = 3 * (row / 3);
	int startcol = 3 * (col / 3);


	for(int i = startrow; i < startrow + 3 ; i++){
		for(int j = startcol; j < startcol + 3; j++){
			if(board[i][j] == ch){
				return false;
			}
		}
	}
	// no number found with ch in board column wise row wise and in sub matrix 3x3
	return true;
}

void printBoard(vector<vector<char>> &board, int N){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
bool solve(vector<vector<char>> &board){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(board[i][j] == '.'){
				for(char ch = '1'; ch <= '9'; ch++){
					if(isValid(i, j, 9, ch, board)){

						board[i][j] = ch;

						if(solve(board)){
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
void solveSudoku(vector<vector<char>>& board) {
	solve(board);
}

int main(){
	
	int N = 9;
	vector<vector<string>> board{ {"5","3",".",".","7",".",".",".","."},
									{"6",".",".","1","9","5",".",".","."},
									{".","9","8",".",".",".",".","6","."},
									{"8",".",".",".","6",".",".",".","3"},
									{"4",".",".","8",".","3",".",".","1"},
									{"7",".",".",".","2",".",".",".","6"},
									{".","6",".",".",".",".","2","8","."},
									{".",".",".","4","1","9",".",".","5"},
									{".",".",".",".","8",".",".","7","9"} 
								};

	vector<vector<char>> board2(N, vector<char> (N,'.'));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			char *charr = (char *) board[i][j].c_str();
			board2[i][j] = charr[0];
		}
	}
	solveSudoku(board2);
	printBoard(board2, 9);
	return 0;
}