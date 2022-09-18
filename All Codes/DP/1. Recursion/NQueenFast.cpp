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




void nqueen(int row, vector<vector<char>> &board, int N, vector<bool> &lowerDiagonal, vector<bool> &upperDiagonal, vector<bool> &colVisited){
	// base case
	if(row == N){
		printBoard(board, N);
		cout << "===================\n";
		return;
	}

	// rec case
	// try to search in each column
	for(int col = 0; col < N; col++){


		if(colVisited[col] == false && upperDiagonal[N-1 + col - row] == false && lowerDiagonal[row + col] == false && board[row][col] == '*'){
				

			board[row][col] = 'Q';
			lowerDiagonal[row + col] = true;
			upperDiagonal[N-1 + col - row] = true;
			colVisited[col] = true;
			

			nqueen(row + 1, board, N, lowerDiagonal, upperDiagonal, colVisited);
			
			board[row][col] = '*';
			lowerDiagonal[row + col] = false;
			upperDiagonal[N-1 + col - row] = false;
			colVisited[col] = false;
		}
	}
}


int main(){
	
	int N; cin>> N;
	vector<bool> lowerDiagonal(N * N, false);
	vector<bool> upperDiagonal(N * N, false);
	vector<bool> colVisited(N, false);
	vector<vector<char>> board(N, vector<char> (N, '*'));

	nqueen(0, board, N, lowerDiagonal, upperDiagonal, colVisited);


	return 0;
}