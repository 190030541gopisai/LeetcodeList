#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void printBinary(int num){
	cout << num << endl;
	for(int i = 10; i >= 0; i--){
		cout << ((num >> i) & 1);
	}
	cout << endl;
}

int main(){
	

	int num = 10; // 1010
	printBinary(num);

	// setting the ith bit
	int i = 2;
	printBinary(num | (1 << i));

	// unsettig the ith bit
	i = 2;
	printBinary(num & (~(1 << i)));	
	// 00000001110
	// 11111111011
	// --------------
	// 00000001010

	// toggling ith bit
	i = 1;
	printBinary(num ^ (1 << i));
	// 00000001010
	// 00000001000 i = 3
	// -----------
	// 00000001000

	// check bit is set or not at ith location
	i = 3;
	if(num & (1 << i)){
		cout << "ith bit is set" << endl;
	}else{
		cout << "ith bit is not set" << endl;
	}
	// 00000001010
	// 00000001000 i = 3
	// -----------
	// 00000001000 !=0 number means true


	// inverting every bit of a number
	num = 10;
	printBinary(~num);

	// twos complement = 1s complement + 1
	num = 10;
	int twoscomplement = -num; // 2s complement
	printBinary(twoscomplement);
	printBinary(~num + 1); // 1s complement + 1

	// stripping off the lowest bit
	num = 7;
	// 111
	// 110
	// ------
	// 110
	printBinary(num & (num - 1)); // removing the lowest set bit

	// getting the  lowest set bit -x==(~x+1)==~(x-1)
	num = 10;
	printBinary(num & (-num)); // first set bit at position 2
	num = 17;
	printBinary(num);
	printBinary(num & (-num)); cout << "---<";


	// divide by 2
	num = 12;
	cout << (num >> 1) << endl;

	// multiplication by 2
	num = 5;
	cout << (num << 1) << endl;


	// 1) Clear all bits from LSB to ith bit 
	num = 29;
	printBinary(num);
	i = 2;
	printBinary(num & (~((1 << (i + 1)) - 1)));

	// 2) Clear all bits from ith bit to MSB
	printBinary(num & (((1 << (i)) - 1)));

	// 5) Upper case English alphabet to lower case 
	char A = 'A';
	cout << char(A | (1 << 5)) << endl;
	cout << char(1 << 5) << endl; // space = 32
	cout << char(A | ' ') << endl;
	

	// 6) Lower case english alphabet to upper case
	char a = 'a';
	cout << char(a & (~(1 << 5))) << endl;
	printBinary(~(1<<5));
	printBinary('_');
	cout << char(a & '_') << endl;


	// check if the number is power of 2
	num = 16;
	if(num & (num - 1) == 0){
		cout << "num = " << num << " is power of 2" << endl; 
	}else{
		cout << "num = " << num << " is NOT power of 2" << endl;
	}


	return 0;
}