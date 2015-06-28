class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
    	if (grid.empty() || grid[0].size() == 0)
    		return 0;
    	int row = grid.size();
    	int col = grid[0].size();
    	vector<vector<int> > res(row, vector<int>(col, 0));
    	res[row - 1][col - 1] = grid[row - 1][col - 1];
    	for (int i = col - 2; i >= 0; i--)
    	    res[row - 1][i] = grid[row - 1][i] + res[row - 1][i + 1];
    	for (int i = row - 2; i >= 0; i--)
    	    res[i][col - 1] = grid[i][col - 1] + res[i + 1][col - 1];
    	for (int i = row - 2; i >= 0; i--) {
    		for (int j = col - 2; j >= 0; j--) {
    				res[i][j] = grid[i][j] + (res[i + 1][j] <= res[i][j + 1] ? res[i + 1][j] : res[i][j + 1]);
    		}
    	}
    	return res[0][0];
    }
};