class Solution {
public:
    bool isPalindrome(string s) {
    	int start = 0;
    	int end = s.size() - 1;
    	while (start < end) {
    		if (s[start] != s[end])
    			return false;
    		start++;
    		end--;
    	}
    	return true;
    }
    void findPartition(vector<vector<string> >& res, vector<string>& v, string s) {
    	if (s.size() == 0) {
    		res.push_back(v);
    		return;
    	}
    	for (int i = 0; i < s.size(); i++) {
    		if (isPalindrome(s.substr(0, i + 1))) {
    			v.push_back(s.substr(0, i + 1));
    			findPartition(res, v, s.substr(i + 1));
    			v.pop_back();
    		}
    	}
    }
    vector<vector<string> > partition(string s) {
    	vector<vector<string> > res;
    	if (s.empty())
    		return res;
    	vector<string> v;
    	findPartition(res, v, s);
    	return res;
    }
};