class Solution {
public:
    void findComb(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& comb, int index) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        else if (target < 0)
            return;
        else {
            for (int i = index; i < candidates.size(); i++) {
                if (i == index || candidates[i] != candidates[i - 1]) {
                    vector<int> v = comb;
                    v.push_back(candidates[i]);
                    findComb(candidates, target - candidates[i], res, v, i + 1);
                }
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> comb;
        
        findComb(candidates, target, res, comb, 0);
        return res;
    }
};