#include<bits/stdc++.h>
#define ll long long int
using namespace std;

string S;

void solve(){
	cin >> S;
	int N = S.length();
	// if(N == 1){
	// 	cout << 0 << " " << 0 << endl;
	// 	cout << 1 << endl;
	// }

	vector<vector<int>> pos(27);
	vector<int> path;
	int cost = 0, jumps = 0;

	for(int i = 0; i < N; i++){
		pos[S[i] - 'a'].push_back(i+1);
	}
	int direction = (S[0] <= S[N-1]) ? 1 : -1;
	for(char c = S[0] ; c != S[N-1] + direction; c += direction){
		vector<int> &temp = pos[c - 'a'];
		for(auto x : temp){
			path.push_back(x);
		}
	}
	cost = abs(S[0]  - S[N-1]);
	cout << cost << " " << path.size() << endl;
	for(int x : path){
		cout << x << " ";
	}
	cout << endl;
}

int main(){
	int t;cin>>t; cin.get();
	while(t-- > 0){
		solve();
	}
	return 0;
}


/*

30493
31399
30834
30506
31092
30735
31567
31344
31754
30021


ITC

*/