class Solution {
public:
    void findComb(vector<vector<int> >& res, vector<int>& v, int count, vector<int>& nums, int last) {
    	if (count == 0) {
    		res.push_back(v);
    		return;
    	}
    	else {
    		for (int i = last + 1; i < nums.size(); i++) {
    			v.push_back(nums[i]);
    			findComb(res, v, count - 1, nums, i);
    			v.pop_back();
    		}
    	}
    }
    vector<vector<int> > subsets(vector<int>& nums) {
    	vector<vector<int> > res;
    	vector<int> v;
    	sort(nums.begin(), nums.end());
    	int len = nums.size();
    	for (int i = 0; i <= len; i++) {
    		findComb(res, v, i, nums, -1);
    	}
    	return res;
    }
};