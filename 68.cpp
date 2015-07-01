class Solution {
public:
    void addLine(vector<string>& res, vector<string>& words, int& len, int& maxWidth, int start, int end, bool last) {
    	string s;
    	if (start == end) {
    		s += words[start];
    		s.append(maxWidth - len, ' ');
    	}
    	else if (last) {
    		int len_space = maxWidth - len;
    		int num_space = end - start;
    		int width_space = len_space / num_space;
    		while (start <= end) {
    			if (s.empty()) {
    				s += words[start];
    				start++;
    			}
    			else {
    				s.append(" " + words[start]);
    				start++;
    			}
    		}
    		s.append(maxWidth - s.size(), ' ');
    	}
    	else {
    		int len_space = maxWidth - len;
    		int num_space = end - start;
    		int width_space = len_space / num_space;
    		int len_extra = start + len_space % num_space;
    		while (start <= end) {
    			if (s.empty()) {
    				s += words[start];
    				start++;
    			}
    			else {
    				if (start <= len_extra) {
    					s.append(width_space + 1, ' ');
    					s += words[start];
    					start++;
    				}
    				else {
    					s.append(width_space, ' ');
    					s += words[start];
    					start++;
    				}
    			}
    		}
    	}
    	res.push_back(s);
    	return;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	vector<string> res;
    	int start = 0;
    	int end = -1;
    	int cur = 0;
    	int len = 0;
    	while (cur < words.size()) {
    		int new_len = len + words[cur].size() + end - start + 1;
    		if (new_len <= maxWidth) {
    			len = len + words[cur].size();
    			end = cur;
    			cur++;
    		}
    		else {
    			addLine(res, words, len, maxWidth, start, end, false);
    			len = 0;
    			start = cur;
    			end = cur - 1;
    		}
    	}
    	if (start < words.size())
    		addLine(res, words, len, maxWidth, start, end, true);
    	return res;
    }
};