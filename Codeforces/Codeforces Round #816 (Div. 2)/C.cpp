#include<bits/stdc++.h>
#define int long long int
using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	vector<int> arr(n+2, -1);

	

	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	int ans = n * (n + 1) / 2;
	for(int i = 1; i < n; i++){
		if(arr[i] != arr[i+1]){
			ans += (i) * (n-i);
		}
	}
	while(m--){
		int i, x; cin >> i >> x;

		if(i - 1 >= 1){
			if(arr[i] != arr[i-1]){
				ans -= (i-1) * (n - (i-1));
			}
		}
		if(i + 1 <= n){
			if(arr[i] != arr[i+1]){
				ans -= (i) * (n-i);
			}
		}

		arr[i] = x;

		if(i - 1 >= 1){
			if(arr[i] != arr[i-1]){
				ans += (i-1) * (n-(i-1));
			}
		}
		if(i + 1 <= n){
			if(arr[i] != arr[i+1]){
				ans += (i) * (n-i);
			}
		}
		cout << ans << endl;
	}
}

int32_t main(){
	// int t;cin>>t;
	// while(t--){
	// 	solve();
	// }
	solve();

	return 0;
}
