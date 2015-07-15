class Solution {
public:
    // bool isReverse(TreeNode* p, TreeNode* q) {
    //     if (!p && !q)
    //         return true;
    //     if (p && !q || !p && q)
    //         return false;
    //     if (p->val != q->val)
    //         return false;
    //     return isReverse(p->left, q->right) && isReverse(p->right, q->left);
    // }
    // bool isSymmetric(TreeNode* root) {
    //     if (!root)
    //         return true;
    //     return isReverse(root->left, root->right);
    // }
    bool isValid(vector<TreeNode*> que) {
        int start = 0;
        int end = que.size() - 1;
        while (start < end) {
            if (!que[start] && !que[end]) {
                start++;
                end--;
                continue;
            }
            if (!que[start] && que[end] || que[start] && !que[end])
                return false;
            if (que[start]->val != que[end]->val)
                return false;
            start++;
            end--;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        vector<TreeNode*> que;
        que.push_back(root);
        while (que.size()) {
            int nums = que.size();
            int i = 0;
            while (i < nums) {
                TreeNode* tn = que.front();
                que.erase(que.begin());
                i++;
                if (!tn)
                    continue;
                que.push_back(tn->left);
                que.push_back(tn->right);
            }
            if (!isValid(que))
                return false;
        }
        return true;
    }
};