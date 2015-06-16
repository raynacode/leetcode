class Solution {
public:
    ListNode* findKth(ListNode* p, int k) {
    	int n = 0;
    	ListNode* cur = p;
    	while (cur && n < k - 1) {
    		cur = cur->next;
    		n++;
    	}
    	if (n == k - 1)
    		return cur;
    	else
    		return NULL;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
    	ListNode* ln = new ListNode(0);
    	ln->next = head;
    
    	ListNode* p1 = ln;
    	ListNode* p2 = head;
    	while (p2 && findKth(p2, k)) {
    		ListNode* p3 = findKth(p2, k);
    		while (p2 != p3) {
    			p1->next = p2->next;
    			p2->next = p3->next;
    			p3->next = p2;
    
    			p2 = p1->next;
    		}
    		p1 = findKth(p1, k + 1);
    		p2 = p1->next;
    	}
    	return ln->next;
    }
};