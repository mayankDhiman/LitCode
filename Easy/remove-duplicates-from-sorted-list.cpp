/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode result(INT_MIN); 
        ListNode* tail = &result;
        tail -> next = NULL;
        int pre = INT_MIN;
        while(head){            
            if ((head -> val) != pre){
                tail -> next = head;
                tail = tail -> next;
            }
            pre = head -> val;
            head = head -> next;
            tail -> next = NULL;
        }
        return result.next;
    }
};