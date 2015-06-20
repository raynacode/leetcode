class Solution {
public:
    void findNext(vector<vector<char> >& bb, int& row, int& col) {
    	for (int i = 0; i < 9; i++) {
    		for (int j = 0; j < 9; j++) {
    			if (bb[i][j] == '.') {
    				row = i;
    				col = j;
    				return;
    			}
    		}
    	}
    	row = 9;
    	col = 9;
    }
    
    unordered_set<char> findOptions(vector<vector<char> >& bb, int row, int col) {
    	unordered_set<char> res;
    	for (char i = '1'; i <= '9'; i++)
    		res.insert(i);
    
    	for (int i = 0; i < 9; i++) {
    		res.erase(bb[row][i]);
    		res.erase(bb[i][col]);
    	}
    
    	for (int i = 0; i < 3; i++) {
    		for (int j = 0; j < 3; j++) {
    			res.erase(bb[3 * (row / 3) + i][3 * (col / 3) + j]);
    		}
    	}
    	return res;
    }
    
    void solveSudoku(vector<vector<char> >& board) {
    	if (board.size() != 9 || board[0].size() != 9)
    		return;
    	queue<vector<vector<char> > > que;
    	que.push(board);
    	unordered_set<char> options;
    	int row = 0;
    	int col = 0;
    
    	while (!que.empty()) {
    		vector<vector<char> > bb = que.front();
    		que.pop();
    		findNext(bb, row, col);
    		if (row == 9 && col == 9) {
    			board = bb;
    			return;
    		}
    		else {
    			options = findOptions(bb, row, col);
    			for (const char& c : options) {
    				bb[row][col] = c;
    				que.push(bb);
    			}
    		}
    	}
    }
};