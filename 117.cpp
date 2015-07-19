class Solution {
public:
    void connect(TreeLinkNode* root) {
        if (!root)
            return;
        TreeLinkNode* level = root;
        while (level) {
            TreeLinkNode* cur = level;
            TreeLinkNode* nextlevel = NULL;
            TreeLinkNode* pre = NULL;
            while (cur) {
                if (!cur->left && !cur->right) {
                    cur = cur->next;
                    continue;
                }
                if (pre) {
                    if (cur->left) {
                        pre->next = cur->left;
                        pre = cur->left;
                    }
                    if (cur->right) {
                        pre->next = cur->right;
                        pre = cur->right;
                    }
                }
                else {
                    if (cur->left) {
                        pre = cur->left;
                        nextlevel = pre;
                    }
                    if (pre && cur->right) {
                        pre->next = cur->right;
                        pre = cur->right;
                    }
                    if (!pre && cur->right) {
                        pre = cur->right;
                        nextlevel = pre;
                    }
                }
                cur = cur->next;
            }
            level = nextlevel;
        }
    }
};