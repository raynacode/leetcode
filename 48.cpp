class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
    	int len = matrix.size();
    	int depth = len / 2;
    	for (int i = 0; i < depth; i++) {
    		for (int j = i; j < len - i - 1; j++) {
    			int tmp = matrix[j][len - i - 1];
    			matrix[j][len - i - 1] = matrix[i][j];
    			matrix[i][j] = matrix[len - j - 1][i];
    			matrix[len - j - 1][i] = matrix[len - i - 1][len - j - 1];
    			matrix[len - i - 1][len - j -1] = tmp;
    		}
    	}
    }
};