class Solution {
public:
    void findCom(vector<vector<int> >& res, vector<int>& v, int last, int n, int count) {
    	if (count == 0) {
    		res.push_back(v);
    		return;
    	}
    	else {
    		for (int i = last + 1; i <= n; i++) {
    			v.push_back(i);
    			findCom(res, v, i, n, count - 1);
    			v.pop_back();
    		}
    	}
    }
    vector<vector<int> > combine(int n, int k) {
    	vector<vector<int> > res;
    	vector<int> v;
    	findCom(res, v, 0, n, k);
    	return res;
    }
};