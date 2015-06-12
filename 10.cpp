class Solution {
public:
    bool isMatch(string s, string p) {
    	int len1 = s.size();
    	int len2 = p.size();
    	vector<vector<int> > v(len1 + 1, vector<int>(len2 + 1, false));
    	v[0][0] = true;
    
    	for (int i = 0; i <= len1; i++) {
    		for (int j = 1; j <= len2; j++) {
    			if (p[j - 1] != '.' && p[j - 1] != '*') {
    				if (i > 0 && s[i - 1] == p[j - 1] && v[i - 1][j - 1])
    					v[i][j] = true;
    			}
    			else if (p[j - 1] == '.') {
    				if (i > 0 && v[i - 1][j - 1])
    					v[i][j] = true;
    			}
    			else if (j > 1) {
    				if (v[i][j - 1] || v[i][j - 2])
    					v[i][j] = true;
    				else if (i > 0 && (s[i - 1] == p [j - 2] || p[j - 2] == '.') && v[i - 1][j])
    					v[i][j] = true;
    			}
    		}
    	}
    	return v[len1][len2];
    }
};