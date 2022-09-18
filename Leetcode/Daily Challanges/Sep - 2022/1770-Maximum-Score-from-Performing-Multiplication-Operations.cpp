#include<bits/stdc++.h>
#define ll long long int
using namespace std;


class Solution {
    int N, M;

    int dp(int start, int idx, vector<int>& nums, vector<int>& multipliers, vector<vector<int>> &memo){
        if(idx == M){
            return 0;
        }
        if(memo[idx][start] != -1){
            return memo[idx][start];
        }
        int end = N - 1 - (idx - start);
        cout << idx << " " <<  start << " " << end << endl;
        int first = multipliers[idx] * nums[start] + dp(start + 1,idx+1, nums, multipliers, memo);
        int last =  multipliers[idx] * nums[end] + dp(start , idx+1, nums, multipliers, memo);
        return memo[idx][start] = max(first, last);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        N = nums.size();
        M = multipliers.size();
        vector<vector<int>> memo(M + 1, vector<int>(M + 1, -1));
        return dp(0, 0, nums, multipliers, memo);
    }
};

void solve(){
    int N, M; cin >> N >> M;
    vector<int> nums(N), multipliers(M);
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }
    for(int i = 0; i < M; i++){
        cin >> multipliers[i];
    }
    Solution s;
    int ans = s.maximumScore(nums, multipliers);
    cout << ans << endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
