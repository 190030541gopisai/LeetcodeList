class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int left = 0, right = 0, n = nums.size();
        vector<int> ans(n - k + 1);
        
        while(right < n){
            
            while(!dq.empty() && nums[dq.back()] <= nums[right]){
                dq.pop_back();
            }
            
            dq.push_back(right);
            
            if(right + 1 >= k){
                ans[left] = nums[dq.front()];
                left++;
            }
            
            if(left > dq.front()){
                dq.pop_front();
            }
            
            right++;
        }
        
        return ans;
    }
};