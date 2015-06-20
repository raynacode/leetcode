class Solution {
public:
    string readStr(string s) {
    	string res;
    	for (int i = 0; i < s.size();) {
    		int j = i + 1;
    		for (; j < s.size() && s[j] == s[i]; j++) {}
    		res += std::to_string(j - i) + s[i];
    		i = j;
    	}
    	return res;
    }
    
    string countAndSay(int n) {
    	if (n == 1)
    		return "1";
    	return readStr(countAndSay(n - 1));
    }
};