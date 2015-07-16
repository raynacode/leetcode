class Solution {
public:
    TreeNode* buildTreePI(vector<int>& preorder, vector<int>& inorder, int s1, int e1, int s2, int e2) {
    	if (s2 > e2)
    		return NULL;
    	int rootval = preorder[s1];
    	int i = s2;
    	for (; i <= e2; i++) {
    		if (inorder[i] == rootval)
    			break;
    	}
    	TreeNode* nd = new TreeNode(rootval);
    	nd->left = buildTreePI(preorder, inorder, s1 + 1, s1 - s2 + i, s2, i - 1);
    	nd->right = buildTreePI(preorder, inorder, s1 - s2 + i + 1, e1, i + 1, e2);
    	return nd;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	return buildTreePI(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};