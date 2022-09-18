#include<bits/stdc++.h>
#define ll long long int
using namespace std;


vector<vector<int>> twoSum(vector<int> &arr, int n, int target, int startIndex){
	vector<vector<int>> ans;
	int low = startIndex, high = n-1;
	while(low < high){
		int sum = arr[low] + arr[high];
		if(sum == target){
			ans.push_back({arr[low], arr[high]});
			while(low < high && arr[low] == arr[low + 1]) low ++;
			while(low < high && arr[high] == arr[high - 1]) high--;
			low++;
			high--;
		}else if(sum < target){
			low++;
		}else{
			high--;
		}
	}
	return ans;
}

vector<vector<int>> ksumHelper(vector<int> &arr, int n, int target, int k, int startIndex){
	vector<vector<int>> res;
	if(startIndex >= n || n - k < 0){
		return res;
	}
	if(k == 2){
		return twoSum(arr, n, target, startIndex);
	}
	for(int index = startIndex; index < n; index++){
		if(index == startIndex || arr[index] != arr[index-1]){
			int val = arr[index];
			vector<vector<int>> subRes = ksumHelper(arr, n, target - val, k-1, index + 1);
			for(auto &lst: subRes){
				lst.push_back(val);
				res.push_back(lst);
			}
		}
	}
	return res;
}

vector<vector<int>> ksum(vector<int> &arr, int n, int target, int k){
	if(n - k < 0){ // no elements to do that much sum
		return {{}};
	}
	sort(arr.begin(), arr.end());
	return ksumHelper(arr, n, target, k, 0);
}

int main(){
	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int target; cin >> target;
	int k; cin >> k;

	vector<vector<int>> ans = ksum(arr, n, target, k);
	for(auto &lst: ans){
		for(int i = 0; i < lst.size(); i++){
			cout << lst[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

/*
[-2,-1,-1,1,1,2,2]
0
*/