class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* pre = root;
        while (!st.empty()) {
            TreeNode* cur = st.top();
            if ((pre == cur->left || pre == cur->right) || (!cur->left && !cur->right)) {
                res.push_back(cur->val);
                pre = cur;
                st.pop();
            }
            else {
                if (cur->right)
                    st.push(cur->right);
                if (cur->left)
                    st.push(cur->left);
            }
        }
        return res;
    }
};