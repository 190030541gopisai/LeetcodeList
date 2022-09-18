#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
using namespace std;

int N;

void solve(){
	
	int mxdays = 0;

	cin >> N;
	vector<int> diff(N);
	
	for(int i = 0; i < N; i++){
		cin >> diff[i];
	}	
	
	for(int i = 0; i < N; i++){
		int y; cin >> y;
		diff[i] = y - diff[i];
	}

	sort(diff.begin(), diff.end());

	int i = 0, j = N-1;
	while(i < j){
		int moneyLeft = diff[j] + diff[i];
		if(moneyLeft >= 0){
			j--;
			mxdays++;
		}
		i++;
	}
	cout << mxdays << endl;
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


// 6
// 7 3 3 6 5 5
// 2 3 2 6 3 2

// (2,7) (3,3) (2,3) (6,6) (3,5) (2, 5)

// (2, 7) (2, 5) ()


// 1 4 1 2 4 2
// 1 3 3 2 3 4

// (1,1) (4,3) (1,3) (2,2) (4,3) (2,4)
// (1,1) (2,2) (1,3) (4, 3) (4,3) (2, 4)

// (6, 6), (3, 5), (3, 3), (2, 7), (2, 5), (2, 3)
// 6 + 3 = 9 + 3 = 12 
// 6 + 5 = 11 + 3 = 14 