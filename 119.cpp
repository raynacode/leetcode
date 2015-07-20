class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur;
        vector<int> next;
        for (int i = 0; i <= rowIndex; i++) {
            if (i == 0)
                cur.push_back(1);
            else {
                for (int j = 0; j <= cur.size(); j++) {
                    if (j == 0)
                        next.push_back(cur[j]);
                    else if (j == cur.size())
                        next.push_back(cur[j - 1]);
                    else
                        next.push_back(cur[j] + cur[j - 1]);
                }
                cur = next;
                next.clear();
            }
        }
        return cur;
    }
};