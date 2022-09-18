#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution{
public:
	vector<int> prevSmaller(vector<int> &A);
};

/*
BruteForce Solution -- O(N^2)

vector<int> Solution::prevSmaller(vector<int> &A) {
	vector<int> ans;
	int N = A.size();
	for(int i = 0; i < N; i++){
		int mn = A[i];
		for(int j = i-1; j >= 0; j--){
			if(mn > A[j]){
				mn = A[j];
				break;
			}
		}
		ans.push_back((mn == A[i])? -1 : mn);
	}
	return ans;
}

*/

/*
	Stack based Approach - 
	Time & space both - O(N)  

*/
vector<int> Solution::prevSmaller(vector<int> &A) {
	vector<int> ans;
	int N = A.size();
	stack<int> stk;
	for(int i = 0; i < N; i++){
		while(!stk.empty() && stk.top() >= A[i]){
			stk.pop();
		}
		if(stk.empty()){
			ans.push_back(-1);
		}else{
			ans.push_back(stk.top());
		}		
		stk.push(A[i]);
	}
	return ans;
}

void solve(){
	int N; cin >> N;
	vector<int> arr(N);
	for(int i = 0; i< N && cin >> arr[i]; i++);
	Solution s;
	for(auto x: s.prevSmaller(arr)){
		cout << x << " ";
	}
	cout << endl;
}

int main(){
	int t;cin>>t;
	while(t-- > 0){
		solve();
	}
	return 0;
}
