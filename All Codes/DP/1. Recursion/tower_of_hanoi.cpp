#include <iostream>

using namespace std;

void tower_of_hanoi(int n, char A, char B, char C){

	if(n == 1){
		cout << A << " --> " << C << endl;
		return;
	}
	tower_of_hanoi(n-1, A, C, B);
	cout << A << " --> " << C << endl;
	tower_of_hanoi(n-1, B, A, C);
}

int main(){
	
	tower_of_hanoi(3, 'A','B','C');
	return 0;
}