class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int len = nums.size();
    	if (len <= 2)
    		return len;
    	int i = 0;
    	int count = 0;
    	for (int j = 1; j < nums.size(); j++) {
    		if (nums[j] == nums[i]) {
    			count++;
    			continue;
    		}
    		if (count > 0) {
    		    i++;
    			nums[i] = nums[i - 1];
    			count = 0;
    		}
    		i++;
    		nums[i] = nums[j];
    	}
    	if (count > 0) {
    	    i++;
    	    nums[i] = nums[i - 1];
    	}
    	return i + 1;
    }
};