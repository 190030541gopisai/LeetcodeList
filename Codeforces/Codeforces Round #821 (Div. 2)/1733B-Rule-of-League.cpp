#include<bits/stdc++.h>
using namespace std;

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


void solve(){
	int N, x, y; cin >> N >> x >> y;
	int a = max(x, y);
	int b = min(x, y);
	if(a == 0 && b == 0){
		cout << -1 << endl;
	}
	else if(a > 0 && b > 0){
		cout << -1 << endl;
	}
	else if((N-1)%a != 0){
		cout << -1 << endl;
	}
	else{
		int val = 2, temp = a;
		for(int i = 0; i < N-1; ){
			if(temp > 0){
				i++;
				cout << val << " ";
				temp--;
			}else{
				temp = a;
				val = val + a;
			}
		}
		cout << endl;
	}

}

int main(){
	int t; cin>>t;
	while(t-- > 0){
		solve();
	}
	return 0;
}
