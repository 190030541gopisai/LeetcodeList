#include<iostream>

using namespace std;


void generate_brackets(int open, int close, int N, string temp){
	if(open == N && close == N){
		cout << temp << endl;
		return;
	}
	if(open < N){
		generate_brackets(open+1, close, N, temp + "(");
	}
	if(close < open){
		generate_brackets(open, close + 1, N, temp + ")");
	}
}

int main(){
	generate_brackets(0, 0, 3, "");	
	return 0;
}