class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
    	if (triangle.empty())
    		return 0;
    	if (triangle.size() == 1)
    		return triangle[0][0];
    	for (int i = 1; i < triangle.size(); i++) {
    		int size = triangle[i].size();
    		for (int j = 0; j < size; j++) {
    			if (j == 0)
    				triangle[i][j] += triangle[i - 1][j];
    			else if (j == size - 1)
    				triangle[i][j] += triangle[i - 1][j - 1];
    			else
    				triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
    		}
    	}
    	std::sort(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
    	return triangle[triangle.size() - 1][0];
    }
};