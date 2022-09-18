#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	if(n==1 && m==1){
	    cout << 0 << endl;
	}
	else if(n==1){
		cout << m << endl;
	}
	else if(m == 1){
		cout << n << endl;
	}
	else{
		int mn = min(n, m);
		int mx = max(n, m);
		cout << (mn-1) * 2 + mx << endl; 
	}
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
    