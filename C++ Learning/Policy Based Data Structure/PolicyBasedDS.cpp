#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag,
										tree_order_statistics_node_update>;

int main(){

	int N; cin >> N;
	ordered_set<int> s;

	for(int i = 0; i < N; i++){
		int x; cin >> x;
		s.insert(x);
	}

	for(auto it: s){
		cout << it << endl;
	}

	int value = *s.find_by_order(1);
	cout << "Index = " <<  value << endl;

	int noless = s.order_of_key(11);
	cout << "Number of less than key = " << noless << endl;

	return 0;
}

// https://youtu.be/f88s33eFGDo?t=430