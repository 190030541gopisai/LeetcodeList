class Solution {
    void merge(int low1, int high1, int low2, int high2, vector<pair<int, int>> &arr, vector<int> &count){
        int i = low1, j = low2, k = 0;
        vector<pair<int, int>> temparr(high2 - low1 + 1);
        
        while(i <= high1 && j <= high2){
            pair<int, int> temp1 = arr[i];
            pair<int, int> temp2 = arr[j];
            
            if(temp1.first <= temp2.first){
                temparr[k++] = arr[j++];
            }else{
                count[temp1.second] += high2 - j + 1;
                temparr[k++] = arr[i++];
            }
        }
        
        while(i <= high1) temparr[k++] = arr[i++];
        while(j <= high2) temparr[k++] = arr[j++];
        
        for(int c = 0; c < k; c++){
            arr[low1 + c] = temparr[c];
        }
    }
    void mergeSort(int low, int high, vector<pair<int, int>> &arr, vector<int> &count){
        if(low < high){
            int mid = low + (high - low)/2;
            mergeSort(low, mid, arr, count);
            mergeSort(mid + 1, high, arr, count);
            merge(low, mid, mid + 1, high, arr, count);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        vector<pair<int, int>> arr(N);
        vector<int> count(N, 0);
        
        for(int i = 0; i < N; i++){
            arr[i] = make_pair(nums[i], i);
        }
        
        mergeSort(0, N-1, arr, count);
        
        return count;
    }
};