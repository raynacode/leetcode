class Solution {
public:
    void findComb(vector<int>& candidates, int target, set<int>& mm, set<vector<int> >& ss, vector<int>& comb) {
        if (target == 0) {
            ss.insert(comb);
            return;
        }
        else if (target < 0)
            return;
        else {
            if (mm.find(target) != mm.end() && (comb.empty() || target >= comb.back())) {
                comb.push_back(target);
                ss.insert(comb);
                comb.pop_back();
            }
            for (int i = 0; i < candidates.size(); i++) {
                if (comb.empty() || candidates[i] >= comb.back()) {
                    vector<int> v = comb;
                    v.push_back(candidates[i]);
                    findComb(candidates, target - candidates[i], mm, ss, v);
                }
            }
        }
    }
    
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    
        sort(candidates.begin(), candidates.end());
        set<int> mm;
        for (int i = 0; i < candidates.size(); i++)
            mm.insert(candidates[i]);
    
        vector<vector<int> > res;
        set<vector<int> > ss;
        vector<int> comb;
        findComb(candidates, target, mm, ss, comb);
        std::copy(ss.begin(), ss.end(), std::back_inserter(res));
    
        return res;
    }
};