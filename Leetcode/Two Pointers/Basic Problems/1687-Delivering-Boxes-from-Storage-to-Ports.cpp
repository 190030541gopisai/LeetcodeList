#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
    const int roundTrip = 2;

public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
    	int N = boxes.size();
        vector<int> diff(N, 0), prewt(N, 0), dp(N+1, 0);

        for(int i = 0; i < N; i++){
        	if(i != 0){
        		diff[i] = diff[i-1] + (i-1 >= 0 && (boxes[i][0] != boxes[i-1][0])? 1 : 0);
        	}
        	prewt[i] += boxes[i][1];
        	if(i != 0){
        		prewt[i] += prewt[i-1];
        	}
        }
        diff[0] = 1;

        int i = 0, j = 0;
        for(j = 0; j < N; j++){
        	int curwt = prewt[j];
        	int curdiff = diff[j];
        	if(i - 1 >= 0){
        		curwt -= prewt[i-1];
        		curdiff -= diff[i-1];
        	}

        	while(i <= j && (curwt > maxWeight || (j - i + 1) > maxBoxes)){
        		i++;
        		curwt = prewt[j];
        	 	curdiff = diff[j];
        	 	if(i - 1 >= 0){
	        		curwt -= prewt[i-1];
	        		curdiff -= diff[i-1];
	        	}
        	}

        	if(curwt <= maxWeight && (j-i+1) <= maxBoxes){
        		dp[j+1] = dp[i] + 2 + curdiff;
        	}
        }

        return dp[N];
    }
};

void solve(){
	int N; 
	cin >> N;

	vector<vector<int>> boxes;
	for(int i = 0; i < N; i++){
		int port, weight; cin >> port >> weight;
		boxes.push_back({port, weight});
	}
	int portsCount, maxBoxes, maxWeight; 
	cin >> portsCount >> maxBoxes >> maxWeight;
	// cout << "done" << endl;
	Solution s;
	int ans = s.boxDelivering(boxes, portsCount, maxBoxes, maxWeight);
	cout << ans << endl;
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
