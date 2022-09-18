#include<bits/stdc++.h>
#define int long long int
using namespace std;

void solve(){
	int n, k, b, s; cin >> n >> k >> b >> s;
	// cout << n  << " " << k << " " << b << " " << s << endl;

	if(s < k * b){
		cout << -1 << endl;
	}else{
		vector<int> arr(n, 0);
		arr[0] = k *b;
		s = s - k * b;
		for(int i = 0; i < n; i++){
			if(s <= 0){
				break;
			}
			arr[i] += min(k-1, s);
			s = s - min(k-1, s);
		}
		if(s > 0){
			cout << -1 << endl;
		}
		else{
			for(int i = 0; i < n; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
}

int32_t main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
