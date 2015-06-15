class Solution {
public:
    struct cmp
    {
    	bool operator () (const ListNode* a, const ListNode* b) {
    		return a->val > b->val;
    	}
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if (lists.empty())
    	    return NULL;
    
    	priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    	for (int i = 0; i < lists.size(); i++) {
    	    if (lists[i])
    		    pq.push(lists[i]);
    	}
    
    	ListNode* l = new ListNode(0);
    	ListNode* res = l;
    	while (!pq.empty()) {
    		ListNode* ln = pq.top();
    		pq.pop();
    		l->next = new ListNode(ln->val);
    		if (ln->next)
    			pq.push(ln->next);
    		l = l->next;
    	}
    	return res->next;
    }
};