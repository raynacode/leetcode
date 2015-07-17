class Solution {
public:
    TreeNode* buildTree(ListNode* head, int len) {
        if (!head || len <= 0)
            return NULL;
        int mid = (len - 1) / 2;
        ListNode* p = head;
        int lenleft = 0;
        while (p) {
            if (lenleft == mid)
                break;
            lenleft++;
            p = p->next;
        }
        TreeNode* root = new TreeNode(p->val);
        root->left = buildTree(head, mid);
        root->right = buildTree(p->next, len - mid - 1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        int len = 0;
        ListNode* p = head;
        while (p) {
            len++;
            p = p->next;
        }
        return buildTree(head, len);
    }
};