class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	if (nums.size() < 2)
    		return;
    
    	int i = nums.size() - 1;
    	for (; i >= 1; i--) {
    		if (nums[i] > nums[i - 1]) {
    			int j = nums.size() - 1;
    			for (; j >= i; j--) {
    				if (nums[j] > nums[i - 1])
    					break;
    			}
    			std::swap(nums[i - 1], nums[j]);
    			std::sort(nums.begin() + i, nums.end());
    			return;
    		}
    	}
    	if (i == 0)
    		std::reverse(nums.begin(), nums.end());
    	return;
    }
};