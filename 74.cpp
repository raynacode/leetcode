class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
    	if (matrix.empty() || matrix[0].empty())
    		return false;
    	int row = -1;
    	for (int i = 0; i < matrix.size(); i++) {
    		if (target >= matrix[i][0] && target <= matrix[i][matrix[i].size() - 1]) {
    			row = i;
    			break;
    		}
    	}
    	if (row == -1)
    		return false;
    
    	int start = 0;
    	int end = matrix[row].size() - 1;
    	while (start <= end) {
    		int mid = (start + end) / 2;
    		if (matrix[row][mid] == target)
    			return true;
    		if (target > matrix[row][mid])
    			start = mid + 1;
    		else
    			end = mid - 1;
    	}
    	return false;
    }
};