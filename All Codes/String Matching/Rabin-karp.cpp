#include<bits/stdc++.h>
#define ll long long int
using namespace std;

#define q INT_MAX // large prime number or 1e9 + 7 is a prime number
#define d 256

void rabin_karp(string s, string pat){
	int N = s.length();
	int M = pat.length();

	int p = 0, t = 0, h = 1; // p = string hash, t = pattern hash, h = pow(D, M-1)

	for(int i = 0; i < M-1; i++){
		h = (h * d) % q; // pow(d, M-1)
	}

	for(int i = 0; i < M; i++){
		p = (p * d + s[i]) % q;
		t = (t * d + pat[i]) % q;
	}

	// aabcd 5 abc 3  5-3 = 2
	// 01234 we loop till 2
	for(int i = 0; i <= (N - M); i++){
		if(p == t){
			int j = 0;
			for(j = 0; j < M; j++){
				if(s[i + j] != pat[j]){
					break;
				}
			}
			if(j == M){
				cout << i << endl;
			}
		}
		if(i < (N - M)){
			t = (d * (t - s[i] * h) + s[i + M]) % q;

			if(t < 0){
				t = t+q;
			}
		}
	}
}

int main(){
	string s, pat; cin >> s >> pat;
	rabin_karp(s, pat);	
	return 0;
}