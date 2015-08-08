class Solution {
public:
void reorderList(ListNode* head) {
	if (!head || !head->next || !head->next->next)
		return;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	// slow is the middle pointer, reverse slow->next to end
	ListNode* cur = slow->next;
	slow->next = NULL;
	ListNode* pre = NULL;
	while (cur) {
		ListNode* tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	ListNode* p1 = head;
	ListNode* p2 = pre;
	while (p1 && p2) {
		ListNode* p3 = p2->next;
		p2->next = p1->next;
		p1->next = p2;
		p1 = p2->next;
		p2 = p3;
	}
}
};