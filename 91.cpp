class Solution {
public:
    bool isDecodabe(string s) {
    	if (s.size() == 1 && s[0] >= '1' && s[0] <= '9')
    		return true;
    	if (s.size() == 2 && (s[0] == '1' || s[0] == '2' && s[1] >= '0' && s[1] <= '6'))
    		return true;
    	return false;
    }
    int numDecodings(string s) {
    	if (s.empty()) 
    		return 0;
    	vector<int> res(s.size(), 0);
    	for (int i = 0; i < s.size(); i++) {
    		if (i == 0)
    			res[0] = isDecodabe(s.substr(0, 1)) ? 1 : 0;
    		else if (i == 1) {
    			if (isDecodabe(s.substr(1, 1)) && isDecodabe(s.substr(0, 1)))
    				res[1]++;
    			if (isDecodabe(s.substr(0, 2)))
    				res[1]++;
    		}
    		else {
    			if (isDecodabe(s.substr(i, 1)))
    				res[i] += res[i - 1];
    			if (isDecodabe(s.substr(i - 1, 2)))
    				res[i] += res[i - 2];
    		}
    	}
    	return res[s.size() - 1];
    }
};