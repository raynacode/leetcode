class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int divd = abs(dividend), divs = abs(divisor);
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        	sign = -1;

        unsigned int res = 0;
        while (divd >= divs)
        {
            long long a = divs;
            int i;
            for(i = 1; a <= divd; i++)
                a <<= 1;
            res += (1 << (i - 2));
            divd -= (divs << (i - 2));
        }
        if (res > std::numeric_limits<int>::max() && sign == 1)
        	return std::numeric_limits<int>::max();
        if (res > std::numeric_limits<int>::max() + 1 && sign == -1)
        	return std::numeric_limits<int>::min();
        return sign * res;
    }
};