class Solution {
public:
    string multiply(string num1, string num2) {
    	if (num1.empty() || num2.empty())
    		return "";
    	string res(num1.size() + num2.size(), '0');
    
    	for (int i = num1.size() - 1; i >= 0; i--) {
    		int n1 = num1[i] - '0';
    		int carry = 0;
    		for (int j = num2.size() - 1; j >= 0; j--) {
    			int n2 = num2[j] - '0';
    			int index = num1.size() - 1 - i + num2.size() - 1 - j;
    			int mul = n1 * n2 + carry + (res[index] - '0');
    			res[index] = mul % 10 + '0';
    			carry = mul / 10;
    		}
    		if (carry > 0)
    			res[num1.size() - 1 - i + num2.size()] = carry + '0';
    	}
    
    	reverse(res.begin(), res.end());
    	int start = 0;
    	while (start < res.size() && res[start] == '0')
    		start++;
    	if (start == res.size())
    		return "0";
    	else
    		return res.substr(start, res.size() - start);
    }
};