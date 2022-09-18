#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> dp, costs;
    int N, M;
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    //  i = ith house , c = color

    int f(int i, int c){
        if(i == N){
            return 0;
        }
        if(dp[i][c] != -1){
            return dp[i][c];
        }
        int ans = INT_MAX;
        for(int color = 0; color < M; color++){
            if( c != color){
                ans = min(ans, costs[i][color] + f(i + 1, color)); 
            }
        }
        return dp[i][c] = ans;
    }
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        this->costs = costs;
        N = costs.size();
        if(N > 0){
            M = costs[0].size();
        }
        dp.clear();
        dp.resize(N, vector<int> (M + 1, -1));
        return f(0, 3);
    }
};

int main(){
    int N; cin>> N;
    vector<vector<int>> costs(N, vector<int> (3));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cin >> costs[i][j];
        }
    }
    Solution s;
    cout << s.minCost(costs) << endl;
    return 0;
}