class Solution {
public:
    void wordBreakHelper(string& s, int start, unordered_set<string>& wordDict, vector<vector<bool> >& mark,vector<string>& res, string str) {
    	if (start >= s.size()) {
    		res.push_back(str);
    		return;
    	}
    	for (int end = start; end < s.size(); end++) {
    		if (mark[start][end]) {
    			if (str.size() == 0)
    				wordBreakHelper(s, end + 1, wordDict, mark, res, s.substr(start, end - start + 1));
    			else
    				wordBreakHelper(s, end + 1, wordDict, mark, res, str + " " + s.substr(start, end - start + 1));
    		}
    	}
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    	int size = s.size();
    	vector<string> res;
    	string str;
    	vector<vector<bool> > mark(size, vector<bool>(size, false));
    	for (int i = 0; i < size; i++) {
    		for (int j = i; j < size; j++) {
    			if (wordDict.find(s.substr(i, j - i + 1)) != wordDict.end())
    				mark[i][j] = true;
    		}
    	}
    	bool flag = false;
    	for (int i = 0; i < size; i++) {
    		if (mark[i][size - 1]) {
    			flag = true;
    			break;
    		}
    	}
    	if (!flag)
    		return res;
    	wordBreakHelper(s, 0, wordDict, mark, res, str);
    	return res;
    }
};