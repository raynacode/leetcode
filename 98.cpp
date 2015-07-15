class Solution {
public:
    bool isBST(TreeNode* t, int min, int max, bool isMin, bool isMax) {
    	if (!t)
    		return true;
    	if (!isMax && t->val >= max || !isMin && t->val <= min)
    		return false;
    	return isBST(t->left, min, t->val, isMin, false) && isBST(t->right, t->val, max, false, isMax);
    }
    bool isValidBST(TreeNode* root) {
    	return isBST(root, INT_MIN, INT_MAX, true, true);
    }
};