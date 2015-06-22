class Solution {
public:
    void findComb(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& comb) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        else if (target < 0)
            return;
        else {
            for (int i = 0; i < candidates.size(); i++) {
                if (comb.empty() || candidates[i] >= comb.back()) {
                    vector<int> v = comb;
                    v.push_back(candidates[i]);
                    findComb(candidates, target - candidates[i], res, v);
                }
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> comb;
        
        findComb(candidates, target, res, comb);
        return res;
    }
};