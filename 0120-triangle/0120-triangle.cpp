class Solution {
    int solve(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>> &dp){
        if(i >= n){
            return 0;
        }
        if(dp[i][j] != INT_MIN){
            return dp[i][j];
        } 
        int down = solve(i+1, j, triangle, n, dp);
        int downRight = solve(i+1, j+1, triangle, n, dp);
        
        return dp[i][j] = triangle[i][j] + min(down, downRight);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, INT_MIN));
        return solve(0, 0, triangle, n, dp);
    }
};