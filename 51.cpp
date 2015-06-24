class Solution {
public:
    bool isValid(vector<string>& v, int row, int col) {
    	for (int i = 0; i < row; i++) {
    		for (int j = 0; j < v[i].size(); j++) {
    			if (v[i][j] == 'Q') {
    				if (j == col || abs(j - col) == (row - i))
    					return false;
    			}
    		}
    	}
    	return true;
    }
    
    void placeQueen(vector<vector<string> >& res, vector<string>& v, int k, int& n) {
    	if (k == n) {
    		res.push_back(v);
    		return;
    	}
    	for (int i = 0; i < n; i++) {
    		if (isValid(v, k, i)) {
    			v[k][i] = 'Q';
    			placeQueen(res, v, k + 1, n);
    			v[k][i] = '.';
    		}
    	}
    }
    
    vector<vector<string> > solveNQueens(int n) {
    	vector<vector<string> > res;
    	vector<string> v(n, string(n, '.'));
    	placeQueen(res, v, 0, n);
    	return res;
    }
};