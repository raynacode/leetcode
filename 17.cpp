class Solution {
public:
    void findComb(string& digits, unordered_map<char, string>& mm, string& s, vector<string>& res, int depth) {
    	if (depth == digits.size()) {
    		res.push_back(s);
    		return;
    	}
    	string str = mm[digits[depth]];
    	for (int i = 0; i < str.size(); i++) {
    		s += str[i];
    		findComb(digits, mm, s, res, depth + 1);
    		s.resize(s.size() - 1);
    	}
    }
    
    vector<string> letterCombinations(string digits) {
    	if (digits.empty())
    		return vector<string>(0, "");
    	unordered_map<char, string> mm;
    	mm['0'] = " ";
    	mm['1'] = "";
    	mm['2'] = "abc";
    	mm['3'] = "def";
    	mm['4'] = "ghi";
    	mm['5'] = "jkl";
    	mm['6'] = "mno";
    	mm['7'] = "pqrs";
    	mm['8'] = "tuv";
    	mm['9'] = "wxyz";
    
    	string s;
    	vector<string> res;
    	findComb(digits, mm, s, res, 0);
    	return res;
    }
};