class Solution {
public:
    int jump(vector<int>& nums) {
    	int res = 0;
    	int maxDist = 0;
    	int last = 0;
    	for (int i = 0; i < nums.size(); i++) {
    		if (i > last) {
    			last = maxDist;
    			res++;
    		}
    		int dist = i + nums[i];
    		maxDist = max(maxDist, dist);
    	}
    	return res;
    }
};