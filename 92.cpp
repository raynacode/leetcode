class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
            return head;
        ListNode* res = new ListNode(0);
        res->next = head;
        ListNode* pm = res;
        ListNode* pn = res;
        ListNode* cur = res;
        int count = 0;
        while (count <= n) {
            if (count == m - 1)
                pm = cur;
            if (count == n)
                pn = cur;
            cur = cur->next;
            count++;
        }
        while (pm->next != pn) {
            cur = pm->next;
            pm->next = cur->next;
            cur->next = pn->next;
            pn->next = cur;
        }
        return res->next;
    }
};