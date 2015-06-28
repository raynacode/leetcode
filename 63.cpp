class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	if (obstacleGrid.empty() || obstacleGrid[0].size() == 0)
    		return 0;
    	int row = obstacleGrid.size();
    	int col = obstacleGrid[0].size();
    	vector<vector<int> > steps(row, vector<int>(col, 0));
    	for (int i = row - 1; i >= 0; i--) {
    		for (int j = col - 1; j >= 0; j--) {
    			if (obstacleGrid[i][j] == 1)
    				steps[i][j] = 0;
    			else if (i == row - 1 && j == col - 1)
    				steps[i][j] = 1;
    			else if (i == row - 1)
    				steps[i][j] = steps[i][j + 1];
    			else if (j == col - 1)
    				steps[i][j] = steps[i + 1][j];
    			else
    				steps[i][j] = steps[i + 1][j] + steps[i][j + 1];
    		}
    	}
    	return steps[0][0];
    }
};