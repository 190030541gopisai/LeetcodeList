const int mod = (int)(1e9 + 7);
class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0;
        for(int i = 1; i <= n; i++){
            int bitlen = log(i)/log(2) + 1;
            ans = ((ans << bitlen) | i) % mod;
        }
        return ans;
    }
};