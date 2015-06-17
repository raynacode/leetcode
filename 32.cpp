class Solution {
public:
    int longestValidParentheses(string s) {
    	if (s.empty())
    		return 0;
    
    	stack<pair<int, int> > st;
    	int len = 0;
    	int maxLen = 0;
    	for (int i = 0; i < s.size(); i++) {
    		if (s[i] == '(')
    			st.push(make_pair(i, 0));
    		else {
    			if (!st.empty() && st.top().second == 0) {
    				st.pop();
    				if (st.empty())
    					len = i + 1;
    				else
    					len = i - st.top().first;
    				maxLen = len > maxLen ? len : maxLen;
    			}
    			else 
    				st.push(make_pair(i, 1));
    		}
    	}
    	return maxLen;
    }
};