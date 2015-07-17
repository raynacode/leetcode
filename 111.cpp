class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int depth = numeric_limits<int>::max();
        if (root->left)
            depth = minDepth(root->left) + 1;
        if (root->right)
            depth = min(depth, minDepth(root->right) + 1);
        return depth;
    }
};