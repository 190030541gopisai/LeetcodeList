#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL)
	{

	}
};


class Solution{
public:
	ListNode* detectCycle(ListNode *head){
		if(head == NULL){
			return NULL;
		}
		ListNode *slow = head, *fast = head;
		while(slow && fast && fast->next && fast->next->next){
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast){
				return slow->next;
			}
		}
		return NULL;
	}
};

class LinkedList{
private:
	ListNode *head , *tail ;
public:
	LinkedList(){
		head = tail = NULL;
	}
	void insert(int val){
		if(head == NULL){
			head = tail = new ListNode(val);
		}
		else{
			tail->next = new ListNode(val);
			tail = tail->next;
		}
	}
	ListNode* getHead(){
		return head;
	}
	void printAll(){
		ListNode *c = head;
		while(c != NULL){
			cout << c->val << " ";
			c = c->next;
		}
	}
};

int main(){
	Solution s;
	LinkedList lst;
	int n; cin >> n;
	// cout << n << endl;
	for(int i = 0; i < n; i++){
		int val = 0; cin >> val;
		// cout << val << " ";
		lst.insert(val);
	}
	// lst.printAll();
	ListNode *head = lst.getHead();
	cout << s.detectCycle(head) << endl;

	// print(print(1) or print(None) and print("hello"))

	return 0;
}