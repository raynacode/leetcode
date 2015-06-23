class Solution {
public:
    void getPermute(vector<int>& nums, vector<vector<int> >& res, vector<int>& v) {
    	if (nums.size() == 0) {
    		res.push_back(v);
    		return;
    	}
    	for (int i = 0; i < nums.size(); ++i) {
    		if (i == 0 || nums[i] != nums[i - 1]) {
    			int val = nums[i];
    			v.push_back(val);
    			nums.erase(nums.begin() + i);
    			getPermute(nums, res, v);
    			nums.insert(nums.begin() + i, val);
    			v.pop_back();
    		}
    	}
    }
    vector<vector<int> > permuteUnique(vector<int>& nums) {
    	vector<vector<int> > res;
    	vector<int> v;
    	std::sort(nums.begin(), nums.end());
    	getPermute(nums, res, v);
    	return res;
    }
};