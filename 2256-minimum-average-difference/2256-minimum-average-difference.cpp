class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int N = nums.size();
        long long int totalSum = 0;
        
        for(auto x : nums){
            totalSum += x;
        }
        
        long long int leftSum = 0, rightSum = 0, minDiff = LLONG_MAX;
        int ans = 0;
        for(int i = 0; i < N; i++){
            leftSum = leftSum + nums[i];
            rightSum = totalSum - leftSum;
            
            long long int diff = (leftSum / (i + 1));
            
            if(i < N - 1){
                diff = abs(diff - rightSum / (N - 1 - i));
            }
            
            if(diff < minDiff){
                ans = i;
                minDiff = diff;
            }
        }
        return ans;
    }
};