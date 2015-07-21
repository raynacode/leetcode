class Solution {
public:
    bool isValid(char c) {
        return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int len = s.size();
        if (len == 0 || len == 1)
            return true;
        int start = 0;
        int end = len - 1;
        while (start < end) {
            if (isValid(s[start]) && isValid(s[end])) {
                if (s[start] == s[end] || abs(s[start] - s[end]) == 32) {
                    start++;
                    end--;
                    continue;
                }
                else
                    return false;
            }
            if (!isValid(s[start]))
                start++;
            if (!isValid(s[end]))
                end--;
        }
        return true;
    }
};