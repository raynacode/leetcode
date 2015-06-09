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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(0);
        ListNode* res = l;
        int carry = 0;
        
        while (l1 || l2) {
            if (l1 && l2) {
                l->next = new ListNode((l1->val + l2->val + carry) % 10);
                carry = (l1->val + l2->val + carry) / 10;
                l1 = l1->next;
                l2 = l2->next;
                l = l->next;
            }
            else if (l1) {
                l->next = new ListNode((l1->val + carry) % 10);
                carry = (l1->val + carry) / 10;
                l1 = l1->next;
                l = l->next;
            }
            else {
                l->next = new ListNode((l2->val + carry) % 10);
                carry = (l2->val + carry) / 10;
                l2 = l2->next;
                l = l->next;
            }
        }
        if (carry != 0)
            l->next = new ListNode(carry);
        
        return res->next;
    }
};
