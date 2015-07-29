class Solution {
public:
    vector<string> findStrSet(string s, unordered_set<string>& wordDict) {
    	vector<string> res;
    	for (int i = 0; i < s.size(); i++) {
    		for (char j = 'a'; j <= 'z'; j++) {
    			if (j != s[i]) {
    				string tmp = s;
    				tmp[i] = j;
    				if (wordDict.find(tmp) != wordDict.end())
    					res.push_back(tmp);
    			}
    		}
    	}
    	return res;
    }

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
    	if (beginWord == endWord)
    		return 1;
    	queue<pair<string, int> > start;
    	queue<pair<string, int> > end;
    	start.push(make_pair(beginWord, 1));
    	end.push(make_pair(endWord, 1));
    	unordered_map<string, bool> sm;
    	unordered_map<string, bool> em;
    	for (auto it = wordDict.begin(); it != wordDict.end(); it++) {
    		sm[*it] = false;
    		em[*it] = false;
    	}
    	sm[beginWord] = true;
    	em[endWord] = true;
    	while (!start.empty() && !end.empty()) {
    		int slen = start.size();
    		int elen = end.size();
    		if (slen <= elen) {
    			for (int i = 0; i < slen; i++) {
    				string cur = start.front().first;
    				int level = start.front().second;
    				vector<string> strSet = findStrSet(cur, wordDict);
    				for (int j = 0; j < strSet.size(); j++) {
    					if (!sm[strSet[j]]) {
    						sm[strSet[j]] = true;
    						if (em[strSet[j]])
    							return level + end.back().second;
    						start.push(make_pair(strSet[j], level + 1));
    					}
    				}
    				start.pop();
    			}
    		}
    		else {
    			for (int i = 0; i < elen; i++) {
    				string cur = end.front().first;
    				int level = end.front().second;
    				vector<string> strSet = findStrSet(cur, wordDict);
    				for (int j = 0; j < strSet.size(); j++) {
    					if (!em[strSet[j]]) {
    						em[strSet[j]] = true;
    						if (sm[strSet[j]])
    							return level + start.back().second;
    						end.push(make_pair(strSet[j], level + 1));
    					}
    				}
    				end.pop();
    			}
    		}
    	}
    	return 0;
    }
};