class Solution {
public:
    string getPermutation(int n, int k) {
    	vector<char> s(n);
    	for (int i = 0; i < n; i++)
    		s[i] = '0' + i + 1;
    	vector<int> fac(n, 1);
    	for (int i = 1; i < n; i++)
    		fac[i] = fac[i - 1] * i;
    
    	k -= 1;
    	string res;
    	for (int i = n; i >= 1; i--) {
    		int j = k / fac[i - 1];
    		k %= fac[i - 1];
    		res.push_back(s[j]);
    		s.erase(s.begin() + j);
    	}
    	return res;
    }
};