class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
    	vector<vector<int> > res;
    	if (nums.size() < 4)
    		return res;
    	unordered_map<int, vector<pair<int, int> > > mm;
    	sort(nums.begin(), nums.end());
    
    	for (int i = 0; i < nums.size() - 1; i++) {
    		for (int j = i + 1; j < nums.size(); j++)
    			mm[nums[i] + nums[j]].push_back(make_pair(i, j));
    	}
    
    	for (int i = 0; i < nums.size() - 3; i++) {
    		if (i > 0 && nums[i] == nums[i - 1])
    			continue;
    		for (int j = i + 1; j < nums.size() - 2; j++) {
    			if (j > i + 1 && nums[j] == nums[j - 1])
    				continue;
    			int sum = target - nums[i] - nums[j];
    			if (mm.find(sum) != mm.end()) {
    				vector<pair<int, int> > v = mm[sum];
    				bool firstPush = true;
    				for (int k = 0; k < v.size(); k++) {
    					if (v[k].first > j && (firstPush || nums[v[k].first] != res.back()[2])) {
    						vector<int> result(4);
    						result[0] = nums[i];
    						result[1] = nums[j];
    						result[2] = nums[v[k].first];
    						result[3] = nums[v[k].second];
    						res.push_back(result);
    						firstPush = false;
    					}
    				}
    			}
    		}
    	}
    	return res;
    }
};