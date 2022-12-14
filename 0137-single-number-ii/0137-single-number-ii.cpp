class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int N = nums.size();
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int countOfOne = 0;
            for(int j = 0; j < N; j++){
                countOfOne += (nums[j] & (1 << i))? 1: 0;
            }
            ans = ((countOfOne % 3) << i) | ans;
        }
        return ans;
    }
};


/*
// TC = O(NlogN) + O(N)
// SC = O(1)
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

*/