class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return NULL;
        ListNode* p1 = head;
        ListNode* p2 = head;
        bool found = false;
        while (p1->next && p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) {
                found = true;
                break;
            }
        }
        if (!found)
            return NULL;
        ListNode* p3 = head;
        while (p3 && p1) {
            if (p3 == p1)
                return p3;
            p3 = p3->next;
            p1 = p1->next;
        }
        return NULL;
    }
};