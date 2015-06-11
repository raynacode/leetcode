class Solution {
public:
    double findKth(vector<int>::iterator it1, int m, vector<int>::iterator it2, int n, int k) {
        if (m > n)
            return findKth(it2, n, it1, m, k);
        if (m == 0)
            return *(it2 + k - 1);
        if (k == 1)
            return min(*it1, *it2);
        
        int k1 = min(m, k / 2);
        int k2 = k - k1;
        
        if (*(it1 + k1 - 1) < *(it2 + k2 - 1))
            return findKth(it1 + k1, m - k1, it2, n, k - k1);
        else if (*(it1 + k1 - 1) > *(it2 + k2 -1))
            return findKth(it1, m, it2 + k2, n - k2, k - k2);
        else
            return *(it1 + k1 - 1);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if (size % 2 == 0)
            return (findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), size / 2) + findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), size / 2 + 1)) / 2;
        else
            return findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), size / 2 + 1);
    }
};