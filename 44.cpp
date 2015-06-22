class Solution {
public:
    bool isMatch(string s, string p) {
        int ii = 0;
        int jj = -1;
    	int i = 0;
    	int j = 0;
    	while (i < s.size()) {
    		if (j < p.size() && (p[j] == '?' || p[j] == s[i])) {
    			i++;
    			j++;
    			continue;
    		}
    		else if (j < p.size() && p[j] == '*') {
    			ii = i;
    			jj = j;
    			j++;
    			continue;
    		}
    		else if (jj >= 0) {
    			i = ii + 1;
    			ii++;
    			j = jj;
    			continue;
    		}
    		return false;
    	}
    	if (i < s.size())
    	    return false;
    	while (p[j] == '*')
    		j++;
    	return j == p.size();
    }
};