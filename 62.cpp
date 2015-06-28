class Solution {
public:
    int uniquePaths(int m, int n) {
    	vector<vector<int> > steps(m, vector<int>(n, 0));
    	for (int i = m - 1; i >= 0; i--) {
    		for (int j = n - 1; j >= 0; j--) {
    			if (i == m -1 && j == n - 1)
    				steps[i][j] = 1;
    			else if (i == m - 1)
    				steps[i][j] = steps[i][j + 1];
    			else if (j == n - 1)
    				steps[i][j] = steps[i + 1][j];
    			else
    				steps[i][j] = steps[i + 1][j] + steps[i][j + 1];
    		}
    	}
    	return steps[0][0];
    }
};