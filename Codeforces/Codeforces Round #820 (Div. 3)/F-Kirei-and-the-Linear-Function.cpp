#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll mod9(ll num){
	return num % 9;
}
void solve(){
	string s; cin >> s;
	ll N = s.length();
	ll W, Q; cin >> W >> Q;
	unordered_map<ll, pair<ll, ll>> m;
	for(ll i = 0; i < 9; i++) m[i] = {0, 0};
	ll sum = 0;
	for(ll i = 0; i < W; i++){
		sum += (s[i] - '0');
	}
	m[mod9(sum)].first = 1;
	for(ll i = W; i < N; i++){
		sum -= (s[i-W] - '0');
		sum += (s[i] - '0');
		if(m[mod9(sum)].first == 0){
			m[mod9(sum)].first = (i - W + 2);
		}
		else if(m[mod9(sum)].second == 0){
			m[mod9(sum)].second = (i - W + 2);
		}
	}
	vector<ll> prefix(N, 0);
	for(ll i = 0; i < N; i++){
		if(i == 0){
			prefix[i] = (s[i] - '0');
		}else{
			prefix[i] = prefix[i-1] + (s[i] - '0');
		}
	}
	while(Q-- > 0){
		vector<pair<ll, ll>> ans;
		ll L, R, K; cin >> L >> R >> K;
		L--;
		R--;
		ll b = (prefix[R]);
		if(L-1 >= 0){
			b = mod9(b - prefix[L-1]);
		}
		for(ll a = 0; a < 9; a++){
			for(ll c = 0; c < 9; c++){
				ll rem = mod9(a * b + c);
				if(rem == K){
					if(a == c){
						if(m[a].first == 0 || m[c].second == 0){
							continue;
						}
						ans.push_back({m[a].first , m[c].second});
					}else{
						if(m[a].first == 0 || m[c].first == 0){
							continue;
						}
						ans.push_back({m[a].first, m[c].first});
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		if(ans.size() == 0){
			cout << -1 << " " << -1 << endl;
		}else{
			cout << ans[0].first << " " << ans[0].second << endl;
		}
	}
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
