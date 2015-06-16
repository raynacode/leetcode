class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	if (!head || !head->next)
    		return head;
    	ListNode* ln = new ListNode(0);
    	ln->next = head;
    
    	ListNode* p1 = ln;
    	ListNode* p2 = head;
    	ListNode* p3 = head->next;
    
    	while (p2 && p3) {
    		p1->next = p3;
    		p2->next = p3->next;
    		p3->next = p2;
    
    		p1 = p2;
    		p2 = p1->next;
    		if (p2) p3 = p2->next;
    	}
    	return ln->next;
    }
};