#include<iostream>
#include<vector>

using namespace std;

int main(){
	int arr[] = {30, 10, 60, 10, 60, 50};
	int N = sizeof(arr) / sizeof(int);
	int prev2 = 0;
	int prev1 = 0;
	for(int index = 1; index < N; index++){
		int firstJump = prev1 + abs(arr[index] - arr[index-1]);
		int secondJump = INT_MAX;
		if(index - 2 >= 0){
			secondJump = prev2 + abs(arr[index] - arr[index - 2]);
		}
		int curi = min(firstJump, secondJump);
		prev2 = prev1;
		prev1 = curi;
	}
	cout << prev1 << endl;
}





// int f(int index, int arr[]){
// 	if(index == 0){
// 		return 0;
// 	}
// 	if(dp[index] != -1){
// 		return dp[index];
// 	}
// 	int firstJump = f(index - 1, arr) + abs(arr[index] - arr[index-1]);
// 	int secondJump = INT_MAX;
// 	if(index - 2 >= 0){
// 		secondJump = f(index - 2, arr) + abs(arr[index] - arr[index - 2]);
// 	}
// 	return dp[index] = min(firstJump, secondJump);
// }