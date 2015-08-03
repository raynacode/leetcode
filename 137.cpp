class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t1 = 0;
        int t2 = 0;
        int t3 = 0;
        for (int i = 0; i < nums.size(); i++) {
            t2 = t2 | t1 & nums[i]; // mark 1-time bits
            t1 = t1 ^ nums[i]; // mark 2-time bits
            t3 = t1 & t2; // mark 3-time bits
            t1 = t1 & ~t3;
            t2 = t2 & ~t3;
        }
        return t1;
    }
};