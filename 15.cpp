class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
    	vector<vector<int> > res;
    	if (nums.size() < 3)
    		return res;
    	sort(nums.begin(), nums.end());
    
    	for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) {
    		if (i > 0 && nums[i] == nums[i - 1])
    			continue;
    
    		int target = -nums[i];
    		unordered_map<int, int> mm;
    
    		for (int j = i + 1; j < nums.size(); j++) {
    			if (mm.find(target - nums[j]) != mm.end() && mm[target - nums[j]] < j && mm[target - nums[j]] > i) {
    				vector<int> v(3);
    				v[0] = nums[i];
    				v[1] = target - nums[j];
    				v[2] = nums[j];
    				if (res.empty() || !(res[res.size() - 1][0] == v[0] && res[res.size() - 1][1] == v[1]))
    					res.push_back(v);
    			}
    			mm[nums[j]] = j;
    		}
    	}
    	return res;
    }
};