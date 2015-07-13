class Solution {
public:
    vector<TreeNode*> genTrees(int min, int max) {
        vector<TreeNode*> res;
        if(min > max) {
        	res.push_back(NULL);
        	return res;
        }
        for (int i = min; i <= max; i++) {
        	vector<TreeNode*> leftTree = genTrees(min, i - 1);
        	vector<TreeNode*> rightTree = genTrees(i + 1, max);
        	for (int j = 0; j < leftTree.size(); j++) {
        		for (int k = 0; k < rightTree.size(); k++) {
        		    TreeNode* root = new TreeNode(i);
        			root->left = leftTree[j];
        			root->right = rightTree[k];
        			res.push_back(root);
        		}
        	}
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return genTrees(1, n);
    }
};