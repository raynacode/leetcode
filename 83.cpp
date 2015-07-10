class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur != NULL) {
            if (cur->val == pre->val) {
                cur = cur->next;
                continue;
            }
            pre = pre->next;
            pre->val = cur->val;
            cur = cur->next;
        }
        pre->next = NULL;
        return head;
    }
};