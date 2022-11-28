/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int getLength(ListNode* head){
        ListNode* cur = head;
        int countNodes = 0;
        while(cur != nullptr){
            countNodes++;
            cur = cur->next;
        }
        return countNodes;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr){
            return nullptr;
        }
        
        int N = getLength(head);
        k = k % N;
        
        if(k == 0){
            return head;
        }
        
        int m = N - k;
        ListNode* prev = nullptr, *cur = head, *newhead = nullptr;
        
        for(int i = 0; i < m; i++){
            prev = cur;
            cur = cur->next;
        }
        newhead = cur;
        
        if(prev){
            prev->next = nullptr;
        }
        
        while(cur != nullptr){
            prev = cur;
            cur = cur->next;
        }
        
        if(prev){
            prev->next = head;
        }
        
        return newhead;
    }
};