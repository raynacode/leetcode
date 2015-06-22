class Solution {
public:
    int trap(vector<int>& height) {
    	if (height.size() == 0)
    		return 0;
    	vector<int> v(height.size(), 0);
    
    	for (int i = 1; i < height.size(); i++) {
    		int maxHeight = -1;
    		int maxIndex = -1;
    	    for (int k = i - 1; k >= 0; k--) {
    	    	if (height[k] > height[i]) {
    	    		maxIndex = k;
    	    		maxHeight = height[k];
    	    		break;
    	    	}
    	    	if (height[k] > maxHeight) {
    	    		maxHeight = height[k];
    	    		maxIndex = k;
    	    	}
    	    }
    		if (height[i] > height[i - 1] && maxHeight > 0) {
    			int minHeight = min(maxHeight, height[i]);
    			int curTrap = 0;
    			for (int j = maxIndex + 1; j < i; j++)
    				curTrap += minHeight - height[j];
    			v[i] = v[maxIndex] + curTrap;
    		}
    		else
    			v[i] = v[i - 1];
    	}
    	return v[height.size() - 1];
    }
};