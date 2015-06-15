class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int len = 0;
        while (p) {
            p = p->next;
            len++;
        }
        if (n == len)
            return head->next;
        
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (n) {
            p1 = p1->next;
            n--;
        }
        while (p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode* toRemove = p2->next;
        p2->next = toRemove->next;
        return head;
    }
};