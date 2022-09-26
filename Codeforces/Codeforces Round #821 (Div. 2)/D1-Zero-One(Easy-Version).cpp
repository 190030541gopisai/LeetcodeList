#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long int
#define ld long double
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define pf push_front
#define mp make_pair
#define first ff
#define second ss
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define sza(x) ((int)x.size())


const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int N;
ll x, y;
string a, b;

void solve(){
	cin >> N >> x >> y >> a >> b; 
	vector<int> diff;
	for(int i = 0; i < N; i++){
		if(a[i] != b[i]){
			diff.pb(i);
		}
	}
	ll d = diff.size();
	if(d == 0){
		cout << 0 << endl;
	}
	else if(d%2 != 0){
		cout << -1 << endl; // odd count of 1s does not make a == b becuase one 1 one remain
	}else if(d == 2 && diff[1] == diff[0]+1){
		cout << min(x, 2*y)<< endl; // since  n>=5 2*y can be possible
	}
	else{
		cout << y * (d/2) << endl; // since x >= y
	}
}

int main(){
	int t; cin>>t;
	while(t-- > 0){
		solve();
	}
	return 0;
}
