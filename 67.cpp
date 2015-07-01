class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        unordered_map<char, int> mm;
        mm['0'] = 0;
        mm['1'] = 1;
        int carry = 0;
        string res;
        while (i >= 0 && j >= 0) {
            int val = (mm[a[i]] + mm[b[j]] + carry) % 2;
            carry = (mm[a[i]] + mm[b[j]] + carry) / 2;
            res += to_string(val);
            i--;
            j--;
        }
        while (i >= 0) {
            int val = (mm[a[i]] + carry) % 2;
            carry = (mm[a[i]] + carry) / 2;
            res += to_string(val);
            i--;
        }
        while (j >= 0) {
            int val = (mm[b[j]] + carry) % 2;
            carry = (mm[b[j]] + carry) / 2;
            res += to_string(val);
            j--;
        }
        if (carry != 0)
            res +=to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};