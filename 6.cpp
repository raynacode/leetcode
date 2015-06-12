class Solution {
public:
    string convert(string s, int numRows) {
    	if (numRows >= s.size() || numRows == 1)
    		return s;
    
    	vector<string> vs(numRows);
    	bool flag = true;
    	for (int i = 0, j = 0; i < s.size(); i++) {
    		vs[j] += s[i];
    		if (flag) {
    			j++;
    			if (j == numRows - 1)
    				flag = false;
    			continue;
    		}
    		if (!flag) {
    			j--;
    			if (j == 0)
    				flag = true;
    			continue;
    		}
    	}
    
    	string res = "";
    	for (int i = 0; i < numRows; i++)
    		res += vs[i];
    	return res;
    }
};