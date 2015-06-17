class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> res;
    	if (words.empty())
    		return res;
    		
        if (words[0].empty()) {
    		res.push_back(0);
    		return res;
	    }
    
    	int num = words.size();
    	int len = words[0].size();
    	unordered_map<string, int> mwords;
    
    	for (int i = 0; i < num; i++)
    		mwords[words[i]]++;
    
    	for (int i = 0; i < s.size() && s.size() - i >= num * len; i++) {
    		string str = s.substr(i, num * len);
    		unordered_map<string, int> mstr;
    		int j = 0;
    		for (; j <= str.size() - len; j += len) {
    			string sstr = str.substr(j, len);
    			mstr[sstr]++;
    			if (mwords.find(sstr) == mwords.end() || mstr[sstr] > mwords[sstr])
    				break;
    		}
    		if (j == str.size())
    			res.push_back(i);
    	}
    	return res;
    }
};