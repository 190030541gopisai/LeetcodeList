#include<bits/stdc++.h>
#define ll long long int
using namespace std;

string getCode(string s, int n){
	string ans = "";
	for(int i = n-1; i >= 0; ){
		if(s[i] == '0'){
			string s_num = "";
			s_num += s[i - 2];
			s_num += s[i - 1];
			ans = char(stoi(s_num) + 'a' - 1) + ans; 
			i-=3;
		}else{
			ans = char((s[i] - '0') + 'a' - 1) + ans;
			i--;
		}
	}
	return ans;
}

void solve(){
	int n; cin >> n; 
	string s; cin >> s;
	// cout << n << " " << s << endl;
	string ans = getCode(s, n);
	cout << ans << endl;
}

int main(){
	int t;cin>>t;
	while(t-- > 0){
		solve();
	}
	return 0;
}
