class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end() && map[target - nums[i]] < i) {
                res[0] = map[target - nums[i]] + 1;
                res[1] = i + 1;
                break;
            }
            map[nums[i]] = i;
        }
        return res;
    }
};
