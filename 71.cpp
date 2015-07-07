class Solution {
public:
    string simplifyPath(string path) {
    	string cur, res;
    	vector<string> dir;
    	path.push_back('/');
    
    	for (int i = 0; i < path.size(); i++) {
    		if (path[i] == '/') {
    			if (cur.empty())
    				continue;
    			else if (cur == ".") {}
    			else if (cur == "..") {
    				if (!dir.empty()) {
    					dir.pop_back();
    				}
    			}
    			else
    				dir.push_back(cur);
    			cur.clear();
    		}
    		else 
    			cur.push_back(path[i]);
    	}
        if (dir.empty())
            res = "/";
    	for (int i = 0; i < dir.size(); i++)
    		res.append("/" + dir[i]);
    	return res;
    }
};