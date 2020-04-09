// Middle of Linked List

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
    ListNode* middleNode(ListNode* head) {
        ListNode* it2 = head;   ListNode* it1 = head;
        while ( (it1 != NULL) && (it1 -> next != NULL)) {
            it1 = it1 -> next -> next;
            it2 = it2 -> next;
        }
        return it2;
    }
};
