class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int> > res(n, vector<int>(n));
    	int depth = n / 2;
    	int count = 1;
    	for (int i = 0; i < depth; i++) {
    		int gap = n - 1 - 2 * i;
    		for (int j = i; j < n - i - 1; j++, count++) {
    			res[i][j] = count;
    			res[j][n - i - 1] = count + gap;
    			res[n - i - 1][n - j - 1] = count + 2 * gap;
    			res[n - j - 1][i] = count + 3 * gap;
    		}
    		count = count + 3 * gap;
    	}
    	if (n % 2 == 1)
    		res[depth][depth] = n * n;
    	return res;
    }
};