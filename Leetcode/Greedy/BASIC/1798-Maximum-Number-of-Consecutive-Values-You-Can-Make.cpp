#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        map<int, int> m;
        for(int ele: coins){
        	m[ele]++;
        }
        int x = 0;
        for(auto it: m){
        	int temp = it.first * it.second;
        	if((x + 1) >= it.first){
        		x += temp;
        	}else{
        		break; // no consecutive numbers can happen
        	}
        }

        return (x + 1); // +1 to add count of 0 
    }
};

int main(){
	
	int N; cin >> N;
	vector<int> coins(N);
	for(int i = 0; i < N && cin >> coins[i]; i++);
	int ans = Solution().getMaximumConsecutive(coins);
	cout << ans << endl;
	return 0;
}