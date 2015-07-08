class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int red = 0;
    	int blue = nums.size() - 1;
    	for (int i = 0; i <= blue;) {
    		if (nums[i] == 0) {
    			if (nums[i] != nums[red])
    				std::swap(nums[i], nums[red]);
    			i++;
    			red++;
    		}
    		else if (nums[i] == 2) {
    			if (nums[i] != nums[blue])
    				std::swap(nums[i], nums[blue]);
    			blue--;
    		}
    		else
    		    i++;
    	}
    }
};