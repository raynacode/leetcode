class Solution {
public:
    int mySqrt(int x) {
        long long low = 0;
        long long high = x;
        if (x <= 0)
            return 0;
        if (x == 1)
            return 1;
        while (high - low > 1) {
            long long mid = (low + high) / 2;
            if (mid * mid <= x)
                low = mid;
            else
                high = mid;
        }
        return low;
    }
};