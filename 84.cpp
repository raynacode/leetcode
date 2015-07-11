class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
    	stack<int> st;
    	height.push_back(0);
    	int res = 0;
    	int area = 0;
    	for (int i = 0; i < height.size();) {
    		if (st.empty() || height[i] >= height[st.top()]) {
    			st.push(i);
    			i++;
    		}
    		else {
    			int h = height[st.top()];
    			st.pop();
    			if (st.empty())
    				area = h * i;
    			else
    				area = h * (i - st.top() - 1);
    			res = max(res, area);
    		}
    	}
    	return res;
    }
};