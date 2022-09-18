#include<iostream>
#include<vector>

using namespace std;

void printBoard(vector<vector<char>> &board, int N){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool isSafe(int row, int col, vector<vector<char>> &board, int N){
	int i = row, j = col;
	// check left upper diagonal
	while(i >= 0 && j >= 0){
		if(board[i][j] == 'Q'){
			return false;
		}
		i--;
		j--;
	}

	// check right upper diagonal
	i = row; j = col;
	while(i >= 0 && j < N){
		if(board[i][j] == 'Q'){
			return false;
		}
		i--;
		j++;
	}

	// check in complete row if queen exist
	i = row; j = col;
	while(i >= 0 && j >= 0){
		if(board[i][j] == 'Q'){
			return false;
		}
		j--;
	}
	i = row; j = col;

	// check in complete column if queen exist
	while(i >= 0 && j>=0){
		if(board[i][j] == 'Q'){
			return false;
		}
		i--;
	}

	return true;
}


void nqueen(int row, vector<vector<char>> &board, int N){
	// base case
	if(row == N){
		printBoard(board, N);
		cout << "===================\n";
		return;
	}

	// rec case
	// try to search in each column
	for(int col = 0; col < N; col++){
		if(isSafe(row,col,board,N)){
			board[row][col] = 'Q';
			nqueen(row + 1, board, N);
			board[row][col] = '*';
		}
	}
}


int main(){
	
	int N; cin>> N;
	vector<vector<char>> board(N, vector<char> (N, '*'));

	nqueen(0, board, N);


	return 0;
}