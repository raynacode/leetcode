class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
    	if (matrix.empty() || matrix[0].empty())
    		return 0;
    	int len1 = matrix.size();
    	int len2 = matrix[0].size();
    	int res = 0;
    	vector<vector<int> > mark(len1, vector<int>(len2, 0));
    	for (int i = 0; i < len1; i++) {
    		for (int j = 0; j < len2; j++) {
    			if (matrix[i][j] == '1') {
    				if (j == 0)
    					mark[i][j] = 1;
    				else
    					mark[i][j] = mark[i][j - 1] + 1;
    			}
    		}
    	}
    	for (int i = 0; i < len1; i++) {
    		for (int j = 0; j < len2; j++) {
    			if (mark[i][j] > 0) {
    				int k = i - 1;
    				int width = mark[i][j];
    				int area = width * (i - k);
    				while (k >= 0 && mark[k][j] > 0) {
    					width = min(width, mark[k][j]);
    					k--;
    					area = max(area, width * (i - k));
    				}
    				res = max(res, area);
    			}
    		}
    	}
    	return res;
    }
};