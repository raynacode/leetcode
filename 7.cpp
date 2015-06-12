class Solution {
public:
    int reverse(int x) {
    	int val = 0;
    	while (x) {
    		if (abs(val) > std::numeric_limits<int>::max() / 10)
    			return 0;
    		val = val * 10 + x % 10;
    		x /= 10;
    	}
    	return val;
    }
};