class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> res;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int val = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            res.push_back(val);
        }
        if (carry != 0)
            res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};