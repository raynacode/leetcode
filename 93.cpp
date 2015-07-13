class Solution {
public:
    bool isValid(string s) {
    	if (s.size() == 0 || s.size() > 3 || atoi(s.c_str()) < 0 || atoi(s.c_str()) > 255)
    		return false;
    	if (s.size() == 2 && s[0] == '0')
    		return false;
    	if (s.size() == 3 && s[0] == '0')
    		return false;
    	return true;
    }
    void findIp(vector<string>& res, string s, string tmp, int count) {
    	if (count == 4) {
    		if(s.empty()) 
    		    res.push_back(tmp);
    		return;
    	}
    	for (int i = 1; i <= 3 && i <= s.size(); i++) {
    		if (isValid(s.substr(0, i))) {
    			if (count == 0)
    				findIp(res, s.substr(i), tmp + s.substr(0, i), count + 1);
    			else
    			    findIp(res, s.substr(i), tmp + "." + s.substr(0, i), count + 1);
    		}
    	}
    }
    vector<string> restoreIpAddresses(string s) {
    	vector<string> res;
    	findIp(res, s, "", 0);
    	return res;
    }
};