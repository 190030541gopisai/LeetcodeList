#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int f(int N, vector<int> &arr, int K){
	int ans = 0;
	sort(arr.begin(), arr.end());

	K = min(K, N);
	int temp = 0;
	for(int i = 0; i < K; i++){
		ans += arr[i];
		temp = arr[i];
	}

	for(int i = K; i < N; i++){
		ans += temp;
	}

	return ans;
}

void solve(){
	int N; cin >> N;
	vector<int> arr(N, 0);
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}	
	int K; cin >> K;

	int ans = f(N, arr, K);
	cout << ans << "\n";
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
