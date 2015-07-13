class Solution {
public:
    void findSubsets(vector<vector<int> >& res, vector<int>& nums, vector<int>& v, int index, int count) {
    	if (count == 0) {
    		res.push_back(v);
    		return;
    	}
    	for (int i = index; i < nums.size(); i++) {
    		if (i != index && nums[i] == nums[i - 1])
    			continue;
    		v.push_back(nums[i]);
    		findSubsets(res, nums, v, i + 1, count - 1);
    		v.pop_back();
    	}
    }
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    	vector<vector<int> > res;
    	sort(nums.begin(), nums.end());
    	for (int i = 0; i <= nums.size(); i++) {
    		vector<int> v;
    		findSubsets(res, nums, v, 0, i);
    	}
    	return res;
    }
};