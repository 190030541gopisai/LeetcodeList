#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 500, M = 500;
int dp[N][M];
void printMat(int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int elephant_path_ways(int n, int m){
	memset(dp, 0, sizeof(int) * (n * m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0 && j == 0){
				dp[0][0] = 1; // one way for one cell
			}
			else{
				int sumRow = 0;
				for(int k = 0; k < j; k++){
					sumRow += dp[i][k];
				}

				int sumCol = 0;
				for(int k = 0; k < i; k++){
					sumCol += dp[k][j];
				}

				dp[i][j] = sumRow + sumCol;
			}
		}
	}
	printMat(n, m);
	return dp[n-1][m-1];
}

int main(){
	int n, m; cin >> n >> m;
	cout << elephant_path_ways(n, m) << endl;
	return 0;
}