class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
    	vector<vector<int> > res;
    	if (!root)
    		return res;
    	vector<TreeNode*> v;
    	v.push_back(root);
    	while(!v.empty()) {
    		vector<int> values;
    		int size = v.size();
    		for(int i = 0; i < size; i++) {
    			TreeNode* t = v.front();
    			v.erase(v.begin());
    			if (t) {
    				values.push_back(t->val);
    				v.push_back(t->left);
    				v.push_back(t->right);
    			}
    		}
    		if (!values.empty())
    			res.push_back(values);
    	}
    	return res;
    }
};