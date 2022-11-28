class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        vector<int>::iterator it = find(nums.begin(), nums.end(), k);
        unordered_map<int, int> cnt;
        int index = it - nums.begin();
        int ans = 0, bal = 0;
        
        for(int i = index; i < nums.size(); i++){
            if(nums[i] < k){
                bal--;
            }else if(nums[i] > k){
                bal++;
            }
            cnt[bal]++;
        }
        
        bal = 0;
        for(int i = index; i >= 0; i--){
            if(nums[i] < k){
                bal--;
            }
            else if(nums[i] > k){
                bal++;
            }
            
            ans += cnt[-bal] + cnt[-bal+1];
        }
        
        return ans;
        
    }
};