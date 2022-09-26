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


void solve(){
	int N; cin >> N;
	int arr[N+1];
	for(int i = 1; i <= N && cin >> arr[i]; i++);

	if(N <= 1){
		cout << 0 << endl;
	}
	else{
		cout << N-1 << endl;
		cout << 1 << " " << N << endl;
		int temp = arr[1] + arr[N];
		if(temp % 2 == 0){
			arr[1] = arr[N];
		}else{
			arr[N] = arr[1];
		}
		for(int i = 2; i <= N-1; i++){
			temp = arr[1] + arr[i];
			if(temp % 2 == 0){
				cout << i << " " << N << endl;
				arr[i] = arr[N];
			}else{
				cout << 1 << " " << i << endl;
				arr[i] = arr[1];
			}
		}

		// for(int i = 1; i <= N; i++){
		// 	cout << arr[i] << " ";
		// }
		// cout << endl;
	}
}

int main(){
	int t; cin>>t;
	while(t-- > 0){
		solve();
	}
	return 0;
}
