class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* p = head->next;
        ListNode* pp = head;
        ListNode* nd = new ListNode(0);
        nd->next = head;
        while (p) {
            ListNode* pre = nd;
            ListNode* cur = nd->next;
            while (cur != p) {
                if (p->val < cur->val) {
                    pp->next = p->next;
                    p->next = cur;
                    pre->next = p;
                    break;
                }
                cur = cur->next;
                pre = pre->next;
            }
            if (cur == p) {
                p = p->next;
                pp = pp->next;
            }
            else {
                p = pp->next;
            }
        }
        return nd->next;
    }
};