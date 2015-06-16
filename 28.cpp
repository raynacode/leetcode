class Solution {
public:
    int strStr(string haystack, string needle) {
    	if (needle.empty())
    		return 0;
    	if (haystack.size() < needle.size())
    		return -1;
    
    	int len = needle.size();
    	for (int i = 0; i < haystack.size(); i++) {
    		if (len + i - 1 < haystack.size() && haystack.substr(i, len) == needle)
    			return i;
    	}
    	return -1;
    }
};