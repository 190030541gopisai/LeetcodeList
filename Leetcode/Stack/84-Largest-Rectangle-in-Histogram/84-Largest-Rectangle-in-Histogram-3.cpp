#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	stack<int> stk; 
        heights.push_back(0);
    	int N = heights.size();
    	int ans = 0;
    	for(int i = 0; i < N; i++){
    		while(!stk.empty() && heights[stk.top()] >= heights[i]){
                int currentLowestBarIndex = stk.top(); 
                stk.pop();
                int edge1 = heights[currentLowestBarIndex];
                // @note: empty meaning just popped lowest bar
                // @note: sk.peek() is
                int edge2 = stk.empty() ? i : (i - 1 - stk.top()); // i-1-peek is ok, since it's monotonic increasing stack
                // calculate area
                ans = max(ans, edge1 * edge2);
            }
            stk.push(i);
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
