class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	ListNode* h = head;
    	int len = 0;
    	while (h != NULL) {
    		h = h->next;
    		len++;
    	}
    	if (len == 0 || len == 1)
    		return head;
    	int steps = k % len;
    	if (steps == 0)
    		return head;
    
    	h = head;
    	ListNode* p1 = head;
    	ListNode* p2 = head;
    	int count = 0;
    	while (count < steps) {
    		p2 = p2->next;
    		count++;
    	}
    	while (p2->next != NULL) {
    		p1 = p1->next;
    		p2 = p2->next;
    	}
    
    	ListNode* res = new ListNode(0);
    	res->next = p1->next;
    	p1->next = NULL;
    	p2->next = head;
    	return res->next;
    }
};