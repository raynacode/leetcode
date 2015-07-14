class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	if (s1.empty() && s2.empty() && s3.empty())
    		return true;
    	int size1 = s1.size();
    	int size2 = s2.size();
    	int size3 = s3.size();
    	if (size1 + size2 != size3)
    		return false;
    	vector<vector<bool> > mark(size1 + 1, vector<bool>(size2 + 1, false));
    	mark[0][0] = true;
    	for (int i = 1; i <= size1; i++)
    		if (mark[i - 1][0] && s1[i - 1] == s3[i - 1])
    			mark[i][0] = true;
    	for (int j = 1; j <= size2; j++)
    		if (mark[0][j - 1] && s2[j - 1] == s3[j - 1])
    			mark[0][j] = true;
    	for (int i = 1; i <= size1; i++) {
    		for (int j = 1; j <= size2; j++) {
    			if (mark[i - 1][j] && s1[i - 1] == s3[i + j - 1] || mark[i][j - 1] && s2[j - 1] == s3[i + j - 1])
    				mark[i][j] = true;
    		}
    	}
    	return mark[size1][size2];
    }
};