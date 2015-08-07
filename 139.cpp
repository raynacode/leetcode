class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
    	int size = s.size();
    	vector<bool> res(size, false);
    	for (int i = 0; i < size; i++) {
    		if (wordDict.find(s.substr(0, i + 1)) != wordDict.end())
    			res[i] = true;
    		else {
    			for (int j = 0; j < i; j++) {
    				if (res[j] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end()) {
    					res[i] = true;
    					break;
    				}
    			}
    		}
    	}
    	return res[size - 1];
    }
};