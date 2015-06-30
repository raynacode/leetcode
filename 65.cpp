class Solution {
public:
    bool isNumber(string s) {
        int cur = 0;
        while (cur < s.size() && s[cur] == ' ')
            cur++;
        bool num = false;
        bool sign = false;
        bool dot = false;
        bool expnt = false;
    
        while (cur < s.size()) {
            if (s[cur] == ' ') {
                while (cur < s.size() && s[cur] == ' ')
                    cur++;
                if (cur == s.size())
                    return num;
                else
                    return false;
            }
            if (s[cur] == '+' || s[cur] == '-') {
                if (sign || num || dot)
                    return false;
                else {
                    sign = true;
                    cur++;
                    continue;
                }
            }
            if (s[cur] == '.') {
                if (dot || expnt)
                    return false;
                else {
                    dot = true;
                    cur++;
                    continue;
                }
            }
            if (s[cur] == 'E' || s[cur] == 'e') {
                if (expnt || !num)
                    return false;
                else {
                    expnt = true;
                    sign = false;
                    num = false;
                    dot = false;
                    cur++;
                    continue;
                }
            }
            if (s[cur] >= '0' && s[cur] <= '9') {
                num = true;
                cur++;
                continue;
            }
            return false;
        }
        return num;
    }
};