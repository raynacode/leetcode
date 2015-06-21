class Solution {
public:
    void findComb(vector<int>& candidates, int target, set<vector<int> >& ss, vector<int>& comb) {
        if (target == 0) {
            ss.insert(comb);
            return;
        }
        else if (target < 0)
            return;
        else {
            for (int i = 0; i < candidates.size(); i++) {
                if (comb.empty() || candidates[i] >= comb.back()) {
                    vector<int> v = comb;
                    v.push_back(candidates[i]);
                    findComb(candidates, target - candidates[i], ss, v);
                }
            }
        }
    }
    
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        set<vector<int> > ss;
        vector<int> comb;
        
        findComb(candidates, target, ss, comb);
        std::copy(ss.begin(), ss.end(), std::back_inserter(res));
    
        return res;
    }
};