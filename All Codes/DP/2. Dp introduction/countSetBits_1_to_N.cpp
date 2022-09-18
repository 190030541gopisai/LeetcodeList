// https://practice.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition0618/1

#include<iostream>

using namespace std;

int main(){
	int N = 16;
	int dp[N+1] = {0};
	dp[0] = 0; // 0 has 0 set bits
	for(int i = 1; i <= N; i++){
		dp[i] = dp[i >> 1] + (i % 2); // or dp[i / 2] + (i %2)
		cout << i << " --> " << dp[i] << endl;
	}	

	return 0;
}