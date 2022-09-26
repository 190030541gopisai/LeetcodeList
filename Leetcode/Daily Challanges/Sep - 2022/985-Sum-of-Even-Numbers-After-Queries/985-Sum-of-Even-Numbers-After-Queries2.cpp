#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long int
#define ld long double
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define pf push_front
#define mp make_pair
#define first ff
#define second ss
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define sza(x) ((int)x.size())


const int MAX_N = 1e4 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    	int N = nums.size();
    	int M = queries.size();
        vector<int> ans(M);
        int sum = 0;
        for(int i = 0; i < N; i++){
        	sum += (nums[i] % 2 == 0)? nums[i] : 0;
        }

        for(int i = 0; i < M; i++){
        	int val = queries[i][0], index = queries[i][1];
        	if(nums[index] % 2 == 0){
        		sum -= nums[index];
        	}
        	nums[index] += val;
        	if(nums[index] % 2 == 0){
        		sum += nums[index];
        	}
        	ans[i] = sum;
        }
        return ans;
    }
};        
void solve(){
	int N, M; cin >> N >> M;
	vector<int> nums(N);
	vector<vector<int>> queries(M);
	for(int i = 0; i < N; i++){
		cin >> nums[i];
	}
	for(int i = 0; i < M; i++){
		int val, index; cin >> val >> index;
		queries[i] = {val, index};
	}
	vector<int> ans = Solution().sumEvenAfterQueries(nums, queries);
	for(auto x: ans){
		cout << x << " ";
	}
	cout << endl;
}

int main(){
	int t; cin>>t;
	while(t-- > 0){
		solve();
	}
	return 0;
}
