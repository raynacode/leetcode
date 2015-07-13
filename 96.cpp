class Solution {
public:
    int numTrees(int n) {
        vector<int> table(n + 1);
        table[0] = table[1] = 1;
        table[2] = 2;
        for (int i = 3; i <= n; i++) {
            int res = 0;
            /** f(0) = 1
             * f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ... + f(n-2)*f(1) + f(n-1)*f(0)
            **/
            for (int j = 0; j <= i - 1; j++) 
                res += table[j] * table[i - 1 - j];
            table[i] = res;
        }
        return table[n];
    }
};