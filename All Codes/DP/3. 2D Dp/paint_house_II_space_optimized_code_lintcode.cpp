class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    // TC - O(N * M)
    // SC - O(M)
    int minCostII(vector<vector<int>> &costs) {
        // write your code here
        int N = costs.size();
        if(N == 0){
            return 0;
        }
        int M = costs[0].size();
        int dp[M];
        memset(dp, 0, sizeof(dp)/sizeof(int));

        int firstMin = INT_MAX, secondMin = INT_MAX;
        for(int j = 0; j < M; j++){
            dp[j] = costs[0][j];

            if(dp[j] <= firstMin){
                secondMin = firstMin;
                firstMin = dp[j];
            }else if(dp[j] <= secondMin){
                secondMin = dp[j];
            }
        }

        for(int i = 1; i < N; i++){
            int newFirstMin = INT_MAX, newSecondMin = INT_MAX;
            for(int j = 0; j < M; j++){
                if(dp[j] == firstMin){
                    dp[j] = costs[i][j] + secondMin;
                }
                else{
                    dp[j] = costs[i][j] + firstMin;
                } 
                
                if(dp[j] <= newFirstMin){
                    newSecondMin = newFirstMin;
                    newFirstMin = dp[j];
                }else if(dp[j] <= newSecondMin){
                    newSecondMin = dp[j];
                }
            }
            firstMin = newFirstMin;
            secondMin = newSecondMin;
        }

        int ans = INT_MAX;
        for(int j = 0; j < M; j++){
            ans = min(ans, dp[j]);
        }
        return ans;
    }
};