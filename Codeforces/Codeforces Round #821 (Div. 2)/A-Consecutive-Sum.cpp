	#include<bits/stdc++.h>
	using namespace std;

	#define int long long int
	const int MAX_N = 105;

	int N, K;
	int arr[MAX_N];
	int ans[MAX_N];
	int dp[MAX_N][MAX_N];


	void solve(){
		cin >> N >> K;
		memset(ans, 0, sizeof(ans));
		for(int i = 1; i <= N; i++){
			cin >> arr[i];
			ans[i % K] = max(arr[i], ans[i % K]);
		}

		int sum = 0;
		for(int i = 0; i <= K; i++){
			sum+=ans[i];
		}
		cout << sum << endl;
	}

	int32_t main(){
		int t; cin>>t;

		while(t-- > 0){
			// cout << "=====\n";
			solve();
		}

		return 0;
	}
