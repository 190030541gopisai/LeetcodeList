#include<bits/stdc++.h>
using namespace std;

struct Node{
	int index;
	int val;
	Node(int _index, int _val){
		index = _index;
		val = _val;
	}
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	stack<Node> stk; 
    	int N = heights.size();
    	int ans = 0;
    	for(int i = 0; i < N; i++){
    		int index = i;
    		while(!stk.empty() && stk.top().val >= heights[i]){
    			index = stk.top().index;
    			ans = max(ans, (i - index) * stk.top().val);
    			stk.pop();
    		}
    		stk.push(Node(index, heights[i]));
    	}
    	while(!stk.empty()){
    		int index = stk.top().index;
    		int val = stk.top().val;
    		ans = max(ans, (N - index) * val);
    		stk.pop();
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
