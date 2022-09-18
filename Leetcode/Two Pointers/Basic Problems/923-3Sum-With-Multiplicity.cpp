#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
    	sort(arr.begin(), arr.end());
        int n = arr.size();
       	int ans = 0;
       	unordered_map<int, int> m;
       	for(int i = 0; i < n; i++){
       		m[arr[i]] = i;
       	}

        for(int i = 0; i < n; i++){
        	for(int j = i+1; j < n; j++){
        		int c = target - (arr[i] + arr[j]);
        		if(m.count(c)){
        			ans++;
        		}
        	}
        }
        return ans;
    }
};

int main(){
	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int target; cin >> target;

	Solution s;
	int ans = s.threeSumMulti(arr, target);
	cout << ans << endl;
	return 0;
}