/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* rotateRight(ListNode *head, int k)
        {
            if (head == nullptr)
            {
                return nullptr;
            }

            int len = 1;
            ListNode *tail = head;

            while (tail->next != nullptr)
            {
                tail = tail->next;
                len++;
            }

            tail->next = head;
            k = k % len;

            if (k == 0)
            {
                tail->next = nullptr;
                return head;
            }
            
            for(int i = 0; i < (len - k); i++){
                tail = tail->next;
            }
            
            ListNode *newhead = tail->next;
            tail->next = nullptr;
            
            return newhead;
            
        }
};