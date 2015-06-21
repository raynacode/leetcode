class Solution {
public:
    void findComb(vector<int>& candidates, int target, set<vector<int> >& ss, vector<int>& comb, int index) {
        if (target == 0) {
            ss.insert(comb);
            return;
        }
        else if (target < 0)
            return;
        else {
            for (int i = index; i < candidates.size(); i++) {
                vector<int> v = comb;
                v.push_back(candidates[i]);
                findComb(candidates, target - candidates[i], ss, v, i + 1);
            }
        }
    }
    
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        set<vector<int> > ss;
        vector<int> comb;
        
        findComb(candidates, target, ss, comb, 0);
        std::copy(ss.begin(), ss.end(), std::back_inserter(res));
        return res;
    }
};