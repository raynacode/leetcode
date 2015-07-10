class Solution {
public:
    bool findWord(vector<vector<char> >& board, vector<vector<bool> >& mark, string& word, int index, int x, int y) {
    	if (index == word.size())
    		return true;
		if (x > 0 && !mark[x - 1][y] && board[x - 1][y] == word[index]) {
		    mark[x - 1][y] = true;
		    if (findWord(board, mark, word, index + 1, x - 1, y))
		        return true;
		    mark[x - 1][y] = false;
		}
		if (x < mark.size() - 1 && !mark[x + 1][y] && board[x + 1][y] == word[index]) {
		    mark[x + 1][y] = true;
		    if (findWord(board, mark, word, index + 1, x + 1, y))
		        return true;
		    mark[x + 1][y] = false;
		}
		if (y > 0 && !mark[x][y - 1] && board[x][y - 1] == word[index]) {
		    mark[x][y - 1] = true;
		    if (findWord(board, mark, word, index + 1, x , y - 1))
		        return true;
		    mark[x][y - 1] = false;
		}
		if (y < mark[0].size() - 1 && !mark[x][y + 1] && board[x][y + 1] == word[index]) {
		    mark[x][y + 1] = true;
		    if (findWord(board, mark, word, index + 1, x , y + 1))
		        return true;
		    mark[x][y + 1] = false;
		}
    	return false;
    }
    bool exist(vector<vector<char> >& board, string word) {
    	if (board.empty() || board[0].empty())
    		return false;
    	if (word.empty())
    		return true;
    	vector<vector<bool> > mark(board.size(), vector<bool>(board[0].size(), false));
    	for (int i = 0; i < board.size(); i++) {
    		for (int j = 0; j < board[i].size(); j++) {
    			if (board[i][j] == word[0]) {
    			    if (word.size() == 1)
    			        return true;
    			    mark[i][j] = true;
    			    if (findWord(board, mark, word, 1, i, j))
    			        return true;
    			    mark[i][j] = false;
    			}
    		}
    	}
    	return false;
    }
};