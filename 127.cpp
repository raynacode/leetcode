class Solution {
public:
    vector<string> findStrSet(string s, unordered_set<string>& wordDict) {
        vector<string> strSet;
        for (int i = 0; i < s.size(); i++) {
            for (char j = 'a'; j <= 'z'; j++) {
                if (j != s[i]) {
                    string tmp = s;
                    tmp[i] = j;
                    if (wordDict.find(tmp) != wordDict.end())
                        strSet.push_back(tmp);
                }
            }
        }
        return strSet;
    }
    
    int ladderLengthHelper(vector<pair<string, int> >& start, vector<pair<string, int> >& end, unordered_set<string>& wordDict, unordered_map<string, bool>& sm, unordered_map<string, bool>& em) {
        if (start.size() > end.size())
            return ladderLengthHelper(end, start, wordDict, em, sm);
        if (start.size() == 0)
            return 0;
        int size = start.size();
        for (int i = 0; i < size; i++)
            wordDict.erase(start[i].first);
        for (int i = 0; i < size; i++) {
            pair<string, int> cur = start.front();
            start.erase(start.begin());
            vector<string> strSet = findStrSet(cur.first, wordDict);
            for (int j = 0; j < strSet.size(); j++) {
                if (em[strSet[j]])
                    return cur.second + end.back().second;
                sm[strSet[j]] = true;
                start.push_back(make_pair(strSet[j], cur.second + 1));
            }
        }
        return ladderLengthHelper(start, end, wordDict, sm, em);
    }
    
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (beginWord == endWord)
            return 1;
        wordDict.insert(beginWord);
        wordDict.insert(endWord);
        unordered_map<string, bool> sm;
        unordered_map<string, bool> em;
        for (auto it = wordDict.begin(); it != wordDict.end(); it++) {
            sm[*it] = false;
            em[*it] = false;
        }
        sm[beginWord] = true;
        em[endWord] = true;
        vector<pair<string, int> > start;
        vector<pair<string, int> > end;
        start.push_back(make_pair(beginWord, 1));
        end.push_back(make_pair(endWord, 1));
        return ladderLengthHelper(start, end, wordDict, sm, em);
    }
};