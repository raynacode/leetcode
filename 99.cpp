class Solution {
public:
    void inorder(TreeNode* cur, TreeNode*& pre, TreeNode*& first, TreeNode*& second) {
    	if (!cur)
    		return;
    	inorder(cur->left, pre, first, second);
    	if (!pre)
    		pre = cur;
    	else {
    		if (cur->val < pre->val) {
    			if (!first)
    				first = pre;
    			second = cur;
    		}
    		pre = cur;
    	}
    	inorder(cur->right, pre, first, second);
    }
    void recoverTree(TreeNode* root) {
    	TreeNode* pre = NULL;
    	TreeNode* first = NULL;
    	TreeNode* second = NULL;
    	inorder(root, pre, first, second);
    	if (first && second) {
    		int tmp = first->val;
    		first->val = second->val;
    		second->val = tmp;
    	}
    }
};