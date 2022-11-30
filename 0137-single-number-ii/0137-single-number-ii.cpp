class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int repeat = 1;
        for(int i = 1; i < N; i++){
            if(nums[i-1] != nums[i]){
                if(repeat == 1){
                    return nums[i-1];
                }
                repeat = 0;
            }
            repeat++;
        }
        return nums[N-1];
    }
};