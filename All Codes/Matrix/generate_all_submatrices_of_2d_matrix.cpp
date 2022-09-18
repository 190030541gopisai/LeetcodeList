#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int R, C;
vector<vector<int>> mat;

void printMat(int startI, int startJ, int endI, int endJ){
	for(int i = startI; i <= endI; i++){
		for(int j = startJ; j <= endJ; j++){
			// cout << mat[i][j] << " ";
			cout << "(" << i << "," << j << ") ";
		}
		cout << endl;
	}
	cout << "===========" << endl;
}

void printAllSubMatrices(){
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			for(int p = 0; p <= i; p++){
				for(int q = 0; q <= j; q++){
					printMat(p, q, i, j);
				}
			}
		}
	}
}
int main(){
	cin >> R >> C;
	mat.resize(R, vector<int>(C));
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> mat[i][j];
		}
	}
	printAllSubMatrices();
	return 0;
}