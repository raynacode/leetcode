class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2)
            return s.size();
        
        int maxLen = 1;
        int start = -1;
        unordered_map<char, int> map;
        
        for (int end = 0; end < s.size(); end++) {
            if (map.find(s[end]) != map.end()) {
                maxLen = end - start - 1 > maxLen ? end - start - 1 : maxLen;
                int k = map[s[end]];
                while (start < k) {
                    map.erase(s[start + 1]);
                    start++;
                }
            }
            map[s[end]] = end;
        }
        
        maxLen = s.size() - start - 1 > maxLen ? s.size() - start - 1 : maxLen;
        return maxLen;
    }
};
