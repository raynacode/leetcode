class Solution {
public:
    int minCut(string s) {
    	if (s.empty())
    		return 0;
    	vector<int> cuts(s.size(), 0);
    	vector<vector<bool> > mark(s.size(), vector<bool>(s.size(), false));
    	for (int i = 0; i < s.size(); i++)
    		cuts[i] = s.size() - i - 1;
    	for (int i = s.size() - 1; i >= 0; i--) {
    		for (int j = i; j < s.size(); j++) {
    			if (s[i] == s[j] && (j - i < 2 || mark[i + 1][j - 1])) {
    				mark[i][j] = true;
    				if (j == s.size() - 1)
    					cuts[i] = 0;
    				else
    					cuts[i] = min(cuts[i], cuts[j + 1] + 1);
    			}
    		}
    	}
    	return cuts[0];
    }
};