class Solution {
public:
    // void connect(TreeLinkNode *root) {
    //     if (!root)
    //         return;
    //     vector<TreeLinkNode*> level;
    //     level.push_back(root);
    //     while (!level.empty()) {
    //         int size = level.size();
    //         TreeLinkNode* pre = NULL;
    //         for (int i = 0; i < size; i++) {
    //             TreeLinkNode* t = level.front();
    //             level.erase(level.begin());
    //             if (t) {
    //                 if (i == 0)
    //                     pre = t;
    //                 else {
    //                     pre->next = t;
    //                     pre = t;
    //                 }
    //                 level.push_back(t->left);
    //                 level.push_back(t->right);
    //             }
    //         }
    //     }
    // }
    void connect(TreeLinkNode* root) {
        if (!root)
            return;
        TreeLinkNode* level = root;
        while (level) {
            TreeLinkNode* cur = level;
            TreeLinkNode* pre = NULL;
            while (cur) {
                if (cur->left && cur->right) {
                    if (!pre) {
                        cur->left->next = cur->right;
                        pre = cur->right;
                    }
                    else {
                        pre->next = cur->left;
                        cur->left->next = cur->right;
                        pre = cur->right;
                    }
                }
                cur = cur->next;
            }
            level = level->left;
        }
    }
};