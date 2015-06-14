class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.empty())
    		return "";
    
    	int len = strs[0].size();
    	for (int i = 0; i < strs.size(); i++) {
    		if (strs[i].size() < len)
    			len = strs[i].size();
    	}
    
    	for (; len >= 1; len--) {
    		int k = 1;
    		for (; k < strs.size(); k++) {
    			if (strs[k].substr(0, len) != strs[k - 1].substr(0, len))
    				break;
    		}
    		if (k == strs.size())
    			return strs[0].substr(0, len);
    	}
    	return "";
    }
};