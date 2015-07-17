class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        TreeNode* cur = root;
        while (cur) {
            if (!cur->left) {
                cur = cur->right;
                continue;
            }
            TreeNode* l = cur->left;
            TreeNode* r = cur->right;
            cur->right = l;
            if (r) {
                TreeNode* p = l;
                while (p->right)
                    p = p->right;
                p->right = r;
            }
            cur->left = NULL;
            cur = cur->right;
        }
    }
};