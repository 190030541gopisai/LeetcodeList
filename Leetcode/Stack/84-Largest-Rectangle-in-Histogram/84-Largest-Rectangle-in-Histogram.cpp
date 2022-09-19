#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// ======================================================
class Solution {
	vector<int> nextSmallerLeft(vector<int> &heights){
		int N = heights.size();
		vector<int> ans(N, 0);
		stack<int> stk;
		for(int i = 0 ; i < N; i++){
			while(!stk.empty() && heights[stk.top()] >= heights[i]){
				stk.pop();
			}
			if(stk.empty()){
				ans[i] = 0;
			}
			else{
				ans[i] = stk.top() + 1;
			}

			stk.push(i);
		}
		return ans;
	}
	vector<int> nextSmallerRight(vector<int> &heights){
		int N = heights.size();
		vector<int> ans(N, N);
		stack<int> stk;
		for(int i = N-1 ; i >= 0; i--){
			while(!stk.empty() && heights[stk.top()] >= heights[i]){
				stk.pop();
			}
			if(stk.empty()){
				ans[i] = N;
			}
			else{
				ans[i] = stk.top();
			}

			stk.push(i);
		}
		return ans;
	}
public:
    int largestRectangleArea(vector<int>& heights) {
    	vector<int> left = nextSmallerLeft(heights);
    	vector<int> right = nextSmallerRight(heights);
    	// for(int x: left){
    	// 	cout << x << " ";
    	// }
    	// cout << endl;
    	// for(int x: right){
    	// 	cout << x <<  " "; 
    	// }
    	// cout << endl;
    	int ans = 0;
    	int N = heights.size();
    	for(int i = 0; i < N; i++){
    		ans = max(ans, abs(right[i] - left[i]) * heights[i]);
    	}
        return ans;
    }
};


void solve(){
	int N; cin >> N;
	vector<int> heights(N); 
	for(int i = 0; i < N && cin >> heights[i]; i++);
	Solution s;
	cout << s.largestRectangleArea(heights) << endl;
}

int main(){
	int t; cin>>t;

	while(t-- > 0){
		solve();
	}

	return 0;
}
