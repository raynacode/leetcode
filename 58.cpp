class Solution {
public:
    int lengthOfLastWord(string s) {
    	stack<pair<int, int> > st;
    	bool spaceMode = true;
    	for (int i = 0; i < s.size(); i++) {
    		if (spaceMode && s[i] != ' ') {
    			st.push(make_pair(i, -1));
    			spaceMode = false;
    		}
    		if (!spaceMode && s[i] == ' ') {
    			st.top().second = i;
    			spaceMode = true;
    		}
    	}
    	if (st.empty())
    		return 0;
    	if (st.top().second == -1)
    		st.top().second = s.size();
    
    	return st.top().second - st.top().first;
    }
};