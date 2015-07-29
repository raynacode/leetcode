class Solution {
public:
    vector<string> findStrSet(string s, unordered_set<string>& dict) {
    	vector<string> result;
    	for (int i = 0; i < s.size(); i++) {
    		for (char j = 'a'; j <= 'z'; j++) {
    			if (j != s[i]) {
    				string tmp = s;
    				tmp[i] = j;
    				if (dict.find(tmp) != dict.end())
    					result.push_back(tmp);
    			}
    		}
    	}
    	return result;
    }
    
    bool findLaddersHelper(unordered_set<string>& level, string& end, unordered_set<string>& dict, unordered_map<string, vector<string> >& nexts) {
    	if (level.empty())
    	    return false;
    	unordered_set<string> next_level;
    	bool found = false;
    	for (auto it = level.begin(); it != level.end(); it++)
    		dict.erase(*it);
    	for (auto it = level.begin(); it != level.end(); it++) {
    		vector<string> strSet = findStrSet(*it, dict);
    		for (int i = 0; i < strSet.size(); i++) {
    			if (strSet[i] == end) {
    				found = true;
    				nexts[*it].push_back(end);
    			}
    			else if (!found) {
    				next_level.insert(strSet[i]);
    				nexts[*it].push_back(strSet[i]);
    			}
    		}
    	}
    	return found || findLaddersHelper(next_level, end, dict, nexts);
    }
    
    void findPath(string start, string& end, unordered_map<string, vector<string> >& nexts, vector<string>& path, vector<vector<string> >& res) {
    	if (start == end) {
    		res.push_back(path);
    	}
    	else {
    		for (auto it = nexts[start].begin(); it != nexts[start].end(); it++) {
    			path.push_back(*it);
    			findPath(*it, end, nexts, path, res);
    			path.pop_back();
    		}
    	}
    }
    
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    	vector<vector<string> > res;
    	vector<string> path(1, start);
    	if (start == end) {
    		res.push_back(path);
    		return res;
    	}
    	dict.insert(end);
    	unordered_set<string> level;
    	level.insert(start);
    	unordered_map<string, vector<string> > nexts;
    	if (findLaddersHelper(level, end, dict, nexts))
    		findPath(start, end, nexts, path, res);
    	return res;
    }
};