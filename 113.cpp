class Solution {
public:
    void findPath(TreeNode* root, int sum, vector<vector<int> >& res, vector<int>& v) {
        if (!root)
            return;
        if (!root->left && !root->right && root->val == sum) {
            v.push_back(root->val);
            res.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(root->val);
        findPath(root->left, sum - root->val, res, v);
        findPath(root->right, sum - root->val, res, v);
        v.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> v;
        findPath(root, sum, res, v);
        return res;
    }
};