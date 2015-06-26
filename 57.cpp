/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> res;
	int index1 = -1;
	int index2 = intervals.size();
	for (int i = 0; i < intervals.size(); i++) {
		if (newInterval.start <= intervals[i].end) {
			index1 = i;
			break;
		}
	}
	for (int i = 0; i < intervals.size(); i++) {
		if (newInterval.end < intervals[i].start) {
			index2 = i;
			break;
		}
	}
	if (index1 == -1) {
		res = intervals;
		res.push_back(newInterval);
		return res;
	}
	if (index2 == 0) {
		res = intervals;
		res.insert(res.begin(), newInterval);
		return res;
	}
	if (index1 == index2) {
		res = intervals;
		res.insert(res.begin() + index1, newInterval);
		return res;
	}
	bool done = false;
	for (int i = 0; i < intervals.size(); i++) {
		if (i < index1 || i >= index2)
			res.push_back(intervals[i]);
		else if (!done) {
			int start = min(newInterval.start, intervals[index1].start);
			int end = max(newInterval.end, intervals[index2 - 1].end);
			res.push_back(Interval(start, end));
			done = true;
		}
	}
	return res;
}
};