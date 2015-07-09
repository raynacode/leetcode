class Solution {
public:
    string minWindow(string s, string t) {
    	int found[256] = {0};
    	int expected[256] = {0};
    	int count = 0;
    	int minW = std::numeric_limits<int>::max();
    	string res;
    	for (int i = 0; i < t.size(); i++)
    		expected[t[i]]++;
    
    	for (int start = 0, end = 0; end < s.size(); end++) {
    		if (expected[s[end]] == 0)
    			continue;
    		found[s[end]]++;
    		if (found[s[end]] <= expected[s[end]])
    			count++;
    		if (count == t.size()) {
    			while (expected[s[start]] == 0 || found[s[start]] > expected[s[start]]) {
    				if (found[s[start]] > expected[s[start]])
    				    found[s[start]]--;
    				start++;
    			}
    			if (end - start + 1 < minW) {
    				minW = end - start + 1;
    				res = s.substr(start, minW);
    			}
    		}
    	}
    	return (count == t.size()) ? res : "";
    }
};