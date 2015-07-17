class Solution {
public:
    int getDepth(TreeNode* root) {
        if (!root)
            return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        if (leftDepth < 0 || rightDepth < 0 || abs(leftDepth - rightDepth) > 1)
            return -1;
        return max(leftDepth, rightDepth) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (getDepth(root) == -1)
            return false;
        return true;
    }
};