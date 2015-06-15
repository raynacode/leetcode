class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int minDiff = std::numeric_limits<int>::max();
    	int res;
    	sort(nums.begin(), nums.end());
    
    	for (int i = 0; i < nums.size() - 2; i++) {
    		int start = i + 1;
    		int end = nums.size() - 1;
    		while (start < end) {
    			int sum = nums[i] + nums[start] + nums[end];
    			int diff = abs(target - sum);
    			if (diff < minDiff) {
    				minDiff = diff;
    				res = sum;
    			}
    			if (minDiff == 0)
    				return res;
    
    			if (sum > target)
    				end--;
    			else if (sum < target)
    				start++;
    		}
    	}
    	return res;
    }
};