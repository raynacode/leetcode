class Solution {
public:
    string longestPalindrome(string s) {
    	int len = s.size();
    	bool mark[len][len];
    	memset(mark, false, len * len * sizeof(bool));
    	int maxLen = 1;
    	int start = 0;
    	int end = 0;
    
    	for (int i = 0; i < len; i++) {
    		mark[i][i] = true;
    
    		for (int j = 0; j < i; j++) {
    			if (s[j] == s[i] && (i - j < 2 || mark[j + 1][i - 1]))
    				mark[j][i] = true;
    
    			if (mark[j][i] && i - j + 1 > maxLen) {
    				maxLen = i - j + 1;
    				start = j;
    				end = i;
    			}
    		}
    	}
    	return s.substr(start, end - start + 1);
    }
};