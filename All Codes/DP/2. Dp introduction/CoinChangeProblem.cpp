#include<iostream>
#include<vector>

using namespace std;

// returns min number of coins needed to get the target value

vector<int> dp;

int coin_change(int target, vector<int> &coins){
	if(target <= 0){
		return 0;
	}
	if(dp[target] != -1){
		return dp[target];
	}
	int mn = INT_MAX;
	for(int i = 0; i < coins.size(); i++){
		if(target - coins[i] >= 0){
			mn = min(mn, coin_change(target - coins[i], coins));
		}
	}
	return dp[target] = mn + 1;
}

int coin_change_bottom_up(int target, vector<int> &coins){
	int numOfCoins = coins.size();
	dp[0] = 0;
	for(int i = 1; i <= target; i++){
		int mn = INT_MAX;
		for(int j = 0; j < numOfCoins; j++){
			if(i - coins[j] >= 0){
				mn = min(mn, dp[i - coins[j]]);
			}
		}
		dp[i] = mn + 1;
	}
	return dp[target];
}

int main(){

	vector<int> coins = {1,7,10};
	int target = 15;
	dp.resize(target+1, -1);

	int coins_required = coin_change(target, coins);
	cout << coins_required << endl;
	
	dp.resize(target+1, 0);
	coins_required = coin_change_bottom_up(target, coins);
	cout << coins_required << endl;

	return 0;
}