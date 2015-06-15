class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(0);
        ListNode* res = l;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                l->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                l->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            l = l->next;
        }
        while (l1) {
            l->next = new ListNode(l1->val);
            l1 = l1->next;
            l = l->next;
        }
        while (l2) {
            l->next = new ListNode(l2->val);
            l2 = l2->next;
            l = l->next;
        }
        return res->next;
    }
};
