class Solution {
public:
    string intToRoman(int num) {
    	int val[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    	string roman[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    	string res;
    
    	for (int i = 12; i >= 0; i--) {
    		int count = num / val[i];
    		if (count != 0) {
    			for (int j = 0; j < count; j++)
    				res.append(roman[i]);
    			num %= val[i];
    		}
    	}
    	return res;
    }
};