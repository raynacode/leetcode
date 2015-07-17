class Solution {
public:
    TreeNode* buildTreeIP(vector<int>& inorder, vector<int>& postorder, int s1, int e1, int s2, int e2) {
    	if (s1 > e1)
    		return NULL;
    	int rootval = postorder[e2];
    	int i = s1;
    	for (; i <= e1; i++) {
    		if (inorder[i] == rootval)
    			break;
    	}
    	TreeNode* nd = new TreeNode(rootval);
    	nd->left = buildTreeIP(inorder, postorder, s1, i - 1, s2, s2 + i - s1 - 1);
    	nd->right = buildTreeIP(inorder, postorder, i + 1, e1, s2 + i - s1, e2 - 1);
    	return nd;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	return buildTreeIP(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};