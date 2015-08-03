class Solution {
public:
    void findSum(TreeNode* root, int& sum, int path) { // should not use reference for path
    	path = path * 10 + root->val;
    	if (!root->left && !root->right) {
    		sum += path;
    		return;
    	}
    	if (root->left)
    		findSum(root->left, sum, path);
    	if (root->right)
    		findSum(root->right, sum, path);
    }
    int sumNumbers(TreeNode* root) {
    	if (!root)
    		return 0;
    	int sum = 0;
    	int path = 0;
    	findSum(root, sum, path);
    	return sum;
    }
};