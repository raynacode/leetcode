class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
    	vector<int> res;
    	if (matrix.size() == 0 || matrix[0].size() == 0)
    		return res;
    	int len1 = matrix.size();
    	int len2 = matrix[0].size();
    	int depth = (min(len1, len2) + 1) / 2;
    
    	for (int i = 0; i < depth; i++) {
    		if (min(len1, len2) % 2 == 1 && len1 <= len2 && i == depth - 1) {
    			for (int j = i; j < len2 - i; j++)
    				res.push_back(matrix[i][j]);
    			break;
    		}
    		if (min(len1, len2) % 2 == 1 && len1 > len2 && i == depth - 1) {
    			for (int j = i; j < len1 - i; j++)
    				res.push_back(matrix[j][len2 - i - 1]);
    			break;
    		}
    		for (int j = i; j < len2 - i - 1; j++)
    			res.push_back(matrix[i][j]);
    		for (int j = i; j < len1 - i - 1; j++)
    			res.push_back(matrix[j][len2 - i - 1]);
    		for (int j = i; j < len2 - i - 1; j++)
    			res.push_back(matrix[len1 - i - 1][len2 - j - 1]);
    		for (int j = i; j < len1 - i - 1; j++)
    			res.push_back(matrix[len1 - j - 1][i]);
    	}
    	return res;
    }
};