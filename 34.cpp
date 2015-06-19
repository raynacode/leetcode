class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> res(2);
    	res[0] = res[1] = -1;
    	int start = 0;
    	int end = nums.size() - 1;
    	bool foundLeft = false;
    
    	while (start <= end) {
    		int mid = (start + end) / 2;
    		if (nums[mid] == target) {
    			if (!foundLeft)
    				if (mid == 0 || nums[mid - 1] < nums[mid]) {
    					res[0] = mid;
    					foundLeft = true;
    					start = 0;
    					end = nums.size() - 1;
    				}
    				else
    					end = mid - 1;
    			else {
    				if (mid == nums.size() - 1 || nums[mid + 1] > nums[mid]) {
    					res[1] = mid;
    					return res;
    				}
    				else
    					start = mid + 1;
    			}
    		}
    		else if (nums[mid] > target)
    			end = mid - 1;
    		else
    			start = mid + 1;
    	}
    	return res;
    }
};