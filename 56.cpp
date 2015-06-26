class Solution {
public:
    static bool compare(const Interval& itv1, const Interval& itv2) {
    	return itv1.start < itv2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
    	vector<Interval> res;
    	std::sort(intervals.begin(), intervals.end(), compare);
    	for (int i = 0; i < intervals.size(); i++) {
    		if (!res.empty() && intervals[i].start <= res.back().end)
    			res.back().end = max(intervals[i].end, res.back().end);
    		else
    			res.push_back(intervals[i]);
    	}
    	return res;
    }
};