class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, bool> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = true;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end())
                continue;
            int cur = nums[i] + 1;
            int count = 0;
            while (m.find(cur) != m.end()) {
                m.erase(cur);
                count++;
                cur++;
            }
            cur = nums[i] - 1;
            while (m.find(cur) != m.end()) {
                m.erase(cur);
                count++;
                cur--;
            }
            if (count + 1 > res)
                res = count + 1;
            m.erase(nums[i]);
        }
        return res;
    }
};