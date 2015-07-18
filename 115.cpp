class Solution {
public:
    // solution 1:
    // int numDistinct(string s, string t) {
    //     vector<int> nums(t.size() + 1, 0);
    //     nums[0] = 1;
    //     for (int i = 1; i <= s.size(); i++) {
    //         for (int j = t.size(); j >= 0; j--) {
    //             if (s[i - 1] == t[j - 1])
    //                 nums[j] += nums[j - 1];
    //         }
    //     }
    //     return nums[t.size()];
    // }
    // solution 2:
    int numDistinct(string s, string t) {
        vector<vector<int> > nums(t.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++)
            nums[0][i] = 1;
        for (int i = 1; i <= t.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (t[i - 1] == s[j - 1]) {
                    nums[i][j] = nums[i- 1][j - 1] + nums[i][j - 1];
                }
                else
                    nums[i][j] = nums[i][j - 1];
            }
        }
        return nums[t.size()][s.size()];
    }
};