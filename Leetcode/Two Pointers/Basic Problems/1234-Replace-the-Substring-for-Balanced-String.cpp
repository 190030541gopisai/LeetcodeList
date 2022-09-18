#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
	bool isBalanced(unordered_map<char, int> &freq, int n){
		int reqFreq = (n/4);
		for(auto &it: freq){
			if(it.second > reqFreq){
				return false;
			}
		}
		return true;
	}
public:
    int balancedString(string s) {
        int L = 0, R = 0;
        int N = s.length();
     	int ans = INT_MAX;

        unordered_map<char, int> freq;
        for(int i = 0; i < N; i++){
        	freq[s[i]]++;
        }

        if(isBalanced(freq, N)){
        	return 0;
        }

        while(R < N){
        	freq[s[R]]--;
        	while(L <= R && isBalanced(freq, N)){
        		ans = min(ans, R - L  + 1);
        		freq[s[L]]++;
        		L++;
        	}
        	R++;
        }
        return ans;
    }
};

int main(){
	Solution s;
	string str; cin >> str;
	cout << s.balancedString(str) << endl;
	return 0;
}