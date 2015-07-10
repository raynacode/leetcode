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
        if (!head || !head->next)
            return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* nd = new ListNode(0);
        nd->next = head;
        ListNode* ppre = nd;
        int count = 0;
        while (cur != NULL) {
            if (cur->val == pre->val) {
                count++;
                cur = cur->next;
                continue;
            }
            if (count > 0) {
                pre->val = cur->val;
                cur = cur->next;
                count = 0;
            }
            else {
                pre = pre->next;
                ppre = ppre->next;
                pre->val = cur->val;
                cur = cur->next;
            }
        }
        if (count > 0)
            ppre->next = NULL;
        else
            pre->next = NULL;
        return nd->next;
    }
};