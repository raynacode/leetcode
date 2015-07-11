class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	int cur = 0;
    	int end = m - 1;
    	for (int i = 0; i < n; i++) {
    		while (cur <= end && nums1[cur] <= nums2[i])
    			cur++;
    		int k = end + 1;
    		while (k > cur) {
    			nums1[k] = nums1[k - 1];
    			k--;
    		}
    		nums1[cur] = nums2[i];
    		end++;
    		cur++;
    	}
    }
};