class Solution {
public:
    int maxArea(vector<int>& height) {
    	int mArea = 0;
    	int minHeight = 0;
    	int start = 0;
    	int end = height.size() - 1;
    
    	while (start < end) {
    		if (min(height[start], height[end]) > minHeight) {
    			minHeight = min(height[start], height[end]);
    			int area = (end - start) * minHeight;
    			if (area > mArea)
    				mArea = area;	
    		}
    		if (height[start] >= height[end])
    			end--;
    		else
    			start++;
    	}
    	return mArea;
    }
};