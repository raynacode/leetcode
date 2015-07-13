class Solution {
public:
    void inorder(vector<int>& res, TreeNode* nd) {
        if (!nd)
            return;
        if (nd->left)
            inorder(res, nd->left);
        res.push_back(nd->val);
        if (nd->right)
            inorder(res, nd->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(res, root);
        return res;
    }
};