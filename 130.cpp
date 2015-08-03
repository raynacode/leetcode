class Solution {
public:
    void solve(vector<vector<char> >& board) {
    	if (board.size() < 3 || board[0].size() < 3)
    		return;
    	int row = board.size();
    	int col = board[0].size();
    	queue<pair<int, int> > que;
    	for (int i = 0; i < row; i++) {
    		if (board[i][0] == 'O')
    			que.push(make_pair(i, 0));
    		if (board[i][col - 1] == 'O')
    			que.push(make_pair(i, col - 1));
    	}
    	for (int j = 1; j < col - 1; j++) {
    		if (board[0][j] == 'O')
    			que.push(make_pair(0, j));
    		if (board[row - 1][j] == 'O')
    			que.push(make_pair(row - 1, j));
    	}
    	while (!que.empty()) {
    		int x = que.front().first;
    		int y = que.front().second;
    		que.pop();
    		board[x][y] = 'Y';
    		if (x > 0 && board[x - 1][y] == 'O')
    			que.push(make_pair(x - 1, y));
    		if (x < row - 1 && board[x + 1][y] == 'O')
    			que.push(make_pair(x + 1, y));
    		if (y > 0 && board[x][y - 1] == 'O')
    			que.push(make_pair(x, y - 1));
    		if (y < col - 1 && board[x][y + 1] == 'O')
    			que.push(make_pair(x, y + 1));
    	}
    	for (int i = 0; i < row; i++) {
    		for (int j = 0; j < col; j++) {
    			if (board[i][j] == 'O')
    				board[i][j] = 'X';
    			if (board[i][j] == 'Y')
    				board[i][j] = 'O';
    		}
    	}
    }
};