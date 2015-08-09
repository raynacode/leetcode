class Solution {
public:
    ListNode* merge(ListNode*& sortedLeft, ListNode*& sortedRight) {
    	ListNode* res = new ListNode(0);
    	ListNode* cur = res;
    	while (sortedLeft && sortedRight) {
    		if (sortedLeft->val < sortedRight->val) {
    			cur->next = sortedLeft;
    			sortedLeft = sortedLeft->next;
    		}
    		else {
    			cur->next = sortedRight;
    			sortedRight = sortedRight->next;
    		}
    		cur = cur->next;
    	}
    	if (sortedLeft)
    		cur->next = sortedLeft;
    	if (sortedRight)
    		cur->next = sortedRight;
    	return res->next;
    }
    
    void split(ListNode* head, ListNode*& left, ListNode*& right) {
    	if (!head->next->next) {
    		left = head;
    		right = head->next;
    		head->next = NULL;
    		return;
    	}
    	ListNode* slow = head;
    	ListNode* fast = head;
    	while (fast->next && fast->next->next) {
    		fast = fast->next->next;
    		slow = slow->next;
    	}
    	left = head;
    	right = slow->next;
    	slow->next = NULL;
    }
    
    ListNode* sortList(ListNode* head) {
    	if (!head || !head->next)
    		return head;
    	ListNode* left = NULL;
    	ListNode* right = NULL;
    	split(head, left, right);
    	ListNode* sortedLeft = sortList(left);
    	ListNode* sortedRight = sortList(right);
    	return merge(sortedLeft, sortedRight);
    }
};