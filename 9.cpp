class Solution {
public:
    bool isPalindrome(int x) {
    	if (x < 0)
    		return false;
    
    	int rev = 0;
    	int val = x;
    	while (val) {
    		if (rev > std::numeric_limits<int>::max() || (rev == std::numeric_limits<int>::max() && val % 10 > std::numeric_limits<int>::max() % 10))
    			return false;
    		rev = rev * 10 + val % 10;
    		val /= 10;
    	}
    
    	if (rev == x)
    		return true;
    	return false;
    } 
};