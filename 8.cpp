class Solution {
public:
    int myAtoi(string str) {
    	int res = 0;
    	int sign = 1;
    	int i = 0;
    
    	while (i < str.size() && str[i] == ' ')
    		i++;
    
    	if (i < str.size() && str[i] == '+')
    		i++;
    	else if (i < str.size() && str[i] == '-') {
    		sign = -1;
    		i++;
    	}
    
    	while (i < str.size() && str[i] == '0')
    		i++;
    
    	for (; i < str.size(); i++) {
    		if (str[i] >= '0' && str[i] <= '9') {
    			int val = (int)(str[i] - '0');
    			if (res > std::numeric_limits<int>::max() / 10 || (res == std::numeric_limits<int>::max() / 10 && val > std::numeric_limits<int>::max() % 10))
    				return sign == 1 ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
    			res = res * 10 + val;
    		}
    		else
    			return sign * res;
    	}
    	return sign * res;
    }
};