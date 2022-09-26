#include<bits/stdc++.h>
#define ll long long int
using namespace std;


vector<int> compute_lps(string &pat){
	int N = pat.length();
	vector<int> lps(N, 0);
	int j = 0, i = 1;

	while(i < N){
		if(pat[i] == pat[j]){
			lps[i] = ++j;
			i++;
		}else{
			if(j > 0){
				j = lps[j-1];
			}	
			else if(j == 0){
				lps[i] = 0;
				i++;
			}
		}
	}

	return lps;
}

void kmp(string &s, string &pat){
	vector<int> lps = compute_lps(pat);
	int N = s.length();
	int M = pat.length();
	int j = 0, i = 0;

	while(i < N){
		if(s[i] == pat[j]){
			i++;
			j++;
			if(j == M){
				cout << (i - j) << endl; // index at which the string matches
				j = lps[j-1];
			}
		}else{
			if(j > 0){
				j = lps[j-1];
			}
			else if(j == 0){
				i++;
			}
		}
	}
}

int main(){
	string s, pat;    cin >> s >> pat;
	kmp(s, pat);
	return 0;
}