class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);
        before->next = head;
        ListNode* after = new ListNode(0);
        ListNode* cur = head;
        ListNode* pre = before;
        ListNode* head_after = after;
        while (cur) {
            if (cur->val >= x) {
                after->next = new ListNode(cur->val);
                after = after->next;
                pre->next = cur->next;
                cur = pre->next;
            }
            else {
                cur = cur->next;
                pre = pre->next;
            }
        }
        pre->next = head_after->next;
        return before->next;
    }
};