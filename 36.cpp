class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	if (board.size() != 9)
    		return false;
    	for (int i = 0; i < 9; i++) {
    		if (board[i].size() != 9)
    			return false;
    	}
    
    	for (int i = 0; i < 9; i++) {
    		unordered_map<char, int> row;
    		for (int j = 0; j < 9; j++) {
    			if (board[i][j] == '.')
    				continue;
    			if (row[board[i][j]] >= 1)
    				return false;
    			row[board[i][j]]++;
    		}
    	}
    	for (int j = 0; j < 9; j++) {
    		unordered_map<char, int> col;
    		for (int i = 0; i < 9; i++) {
    			if (board[i][j] == '.')
    				continue;
    			if (col[board[i][j]] >= 1)
    				return false;
    			col[board[i][j]]++;
    		}
    	}
    	for (int i = 0; i < 9; i += 3) {
    		for (int j = 0; j < 9; j +=3) {
    			unordered_map<char, int> block;
    			for (int ii = i; ii < i + 3; ii++) {
    				for (int jj = j; jj < j + 3; jj++) {
    					if (board[ii][jj] == '.')
    						continue;
    					if (block[board[ii][jj]] >= 1)
    						return false;
    					block[board[ii][jj]]++;
    				}
    			}
    		}
    	}
    	return true;
    }
};