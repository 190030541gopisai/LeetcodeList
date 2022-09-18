#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){

	}
};


class Solution{
public:
	bool hasCycle(ListNode *head){
		if(head == NULL){
			return false;
		}
		ListNode *slow = head, *fast = head;
		
		while(fast->next && fast->next->next){
			slow = slow->next;
			fast = fast->next->next;
            if(slow == fast){
				return true;
			}
		}
		return false;
	}
};


int main(){
	Solution s;
	ListNode *head = new ListNode(1);
	
	ListNode *node1 = new ListNode(2);
	ListNode *node2 = new ListNode(3);
	ListNode *node3 = new ListNode(4);
	ListNode *node4 = new ListNode(5);

	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node3;

	cout << s.hasCycle(head) << endl;
	return 0;
}