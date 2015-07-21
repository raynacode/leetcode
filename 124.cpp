class Solution {
public:
    int findSum(TreeNode* root, int& maxSum) {
        if (!root->left && !root->right) {
            maxSum = max(maxSum, root->val);
            return root->val;
        }
        int sum = root->val;
        int leftval = 0;
        int rightval = 0;
        if (root->left) {
            if ((leftval = findSum(root->left, maxSum)) > 0)
                sum += leftval;
        }
        if (root->right) {
            if ((rightval = findSum(root->right, maxSum)) > 0)
                sum += rightval;
        }
        maxSum = max(maxSum, sum);
        return max(max(leftval, rightval) + root->val, root->val);
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        int maxSum = root->val;
        findSum(root, maxSum);
        return maxSum;
    }
};