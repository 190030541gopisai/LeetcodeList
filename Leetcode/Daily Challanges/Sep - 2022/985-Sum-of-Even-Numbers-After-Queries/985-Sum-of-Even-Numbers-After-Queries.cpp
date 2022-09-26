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

int tree[4 * MAX_N];

int left(int index){
	return 2*index + 1;
}

int right(int index){
	return 2*index + 2;
}

void buildTree(int ss, int se, int index, vector<int> &nums){
	if(ss == se){
		tree[index] = (nums[ss] % 2 != 0)? 0: nums[ss];
		return;
	}
	int mid = ss + (se - ss)/2;
	buildTree(ss, mid, left(index), nums);
	buildTree(mid + 1, se, right(index), nums);
	tree[index] = tree[left(index)] + tree[right(index)];
}

void update(int ss, int se, int index, int i, int val, vector<int> &nums){
	if(i < ss || se < i){
		return;
	}
	if(ss == se && ss == i){
		nums[i] += val;
		tree[index] = (nums[i] % 2 != 0)? 0: nums[i];
		return;
	}
	int mid = ss + (se - ss)/2;
	update(ss, mid, left(index), i, val, nums);
	update(mid + 1, se, right(index), i, val, nums);
	tree[index] = tree[left(index)] + tree[right(index)];
}


class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    	int N = nums.size();
    	int M = queries.size();
        vector<int> ans(M);

    	memset(tree, 0, sizeof(tree));
        buildTree(0, N-1, 0, nums);

        for(int i = 0; i < M; i++){
        	int val = queries[i][0];
        	int index = queries[i][1];
        	update(0, N-1, 0, index, val, nums);
        	ans[i] = push_back(tree[0]);
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
