#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> dp;

int greddy_wine(int *wines, int N){
	int i = 0, j = N-1;
	int year = 1;
	int mxprice = 0;
	while(i <= j){
		if(wines[i] <= wines[j]){
			mxprice += wines[i] * year;
			i++;
		}
		else{
			mxprice += wines[j] * year;
			j--;
		}
		year++;
	}
	return mxprice;
}

int top_down_wine(int start, int end, int year, int *wines){
	if(start > end){
		return 0;
	}
	if(dp[start][end] != -1){
		return dp[start][end];
	}
	if(start == end){
		return dp[start][end] = wines[start] * year;
	}
	int left = wines[start] * year + top_down_wine(start + 1, end, year + 1, wines);
	int right = wines[end] * year + top_down_wine(start, end - 1, year + 1, wines);

	return dp[start][end] = max(left, right);
}

int bottom_up_wine(int start, int end, int *wines, int N){

	for(int i = 0; i < N; i++){
		int year = N;
		dp[i][i] = year * wines[i];
	}
	for(int i = N-2; i >= 0; i--){
		for(int j = i + 1; j < N; j++){
			int year = N - (j - i);
			int left = wines[i] * year + dp[i + 1][j];
			int right = wines[j] * year + dp[i][j-1];

			dp[i][j] = max(left,right);
		}
	}
	return dp[start][end];
}

int main(){
	
	int winePrices[] = {2,3,5,1,4};
	int N = sizeof(winePrices) / sizeof(int);

	// 2 * 1 + 3 * 2 + 4 * 3 + 1 * 4 + 5 * 5
	// 2 + 6 + 12 + 4 + 25
	cout << "Greedy = " << greddy_wine(winePrices, N) << endl;

	dp.resize(N, vector<int> (N, -1));
	cout << "DP top down = " << top_down_wine(0, N-1, 1, winePrices) << endl;

	dp.resize(N, vector<int> (N, 0));
	cout << "DP Bottom Up = " << bottom_up_wine(0, N-1, winePrices, N) << endl;


	return 0;
}