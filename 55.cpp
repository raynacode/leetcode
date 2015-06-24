class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int lastDist = 0;
    	for (int i = 0; i < nums.size(); i++) {
    		if (i > lastDist)
    			return false;
    		else {
    			lastDist = max(lastDist, i + nums[i]);
    			if (lastDist >= nums.size() - 1)
    				return true;
    		}
    	}
    	return false;
    }
};