class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        int val1 = 0;
        int val2 = 0;
        int size = s1.size();
        for (int i = 0; i < size; i++) {
            val1 += s1[i] - 'a';
            val2 += s2[i] - 'a';
        }
        if (val1 != val2)
            return false;
        for (int i = 1; i < size; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(size - i)) && isScramble(s1.substr(i), s2.substr(0, size - i)))
                return true;
        }
        return false;
    }
};