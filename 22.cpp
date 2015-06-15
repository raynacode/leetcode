class Solution {
public:
    void generator(vector<string>& res, string& s, int& n, int left, int right) {
    	if (left == n && right == n) {
    		res.push_back(s);
    		return;
    	}
    	if (left < n) {
    		s += "(";
    		generator(res, s, n, left + 1, right);
    		s.resize(s.size() - 1);
    	}
    	if (left > right) {
    		s += ")";
    		generator(res, s, n, left, right + 1);
    		s.resize(s.size() - 1);
    	}
    }
    
    vector<string> generateParenthesis(int n) {
    	vector<string> res;
    	string s;
    	generator(res, s, n, 0, 0);
    	return res;
    }
};