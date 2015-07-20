class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows == 0)
            return res;
        res.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            vector<int> v = res[i - 1];
            vector<int> next;
            for (int j = 0; j <= v.size(); j++) {
                if (j == 0)
                    next.push_back(v[j]);
                else if (j == v.size())
                    next.push_back(v[j - 1]);
                else
                    next.push_back(v[j] + v[j - 1]);
            }
            res.push_back(next);
        }
        return res;
    }
};