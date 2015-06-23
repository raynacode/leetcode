class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
    	vector<string> res;
    	unordered_map<string, int> mm;
    	for (int i = 0; i < strs.size(); i++) {
    		string s = strs[i];
    		sort(s.begin(), s.end());
    		if (mm.find(s) != mm.end()) {
    			res.push_back(strs[i]);
    			if (mm[s] != -1) {
    				res.push_back(strs[mm[s]]);
    				mm[s] = -1;
    			}
    		}
    		else
    			mm[s] = i;
    	}
    	return res;
    }
};