#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag,
										tree_order_statistics_node_update>;

int main(){
	// in order to use duplicates we should use pair to keep value and index so that we can insert duplicate
	// values inside the policy based data structure
 	ordered_set<pair<int, int>> s;
 	s.insert({10, 0});
 	s.insert({20, 1});
 	s.insert({5, 2});

 	cout << s.find_by_order(1)->first << " " << s.find_by_order(1)->second << endl;
 	cout << s.order_of_key({10, 0}) << endl;
}									