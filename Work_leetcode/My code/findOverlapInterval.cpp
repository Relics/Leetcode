/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool myCompare(Interval& a, Interval& b){
    if (a.end != b.end) 
        return a.end < b.end;
    else
        return a.start < b.start;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if ((int)intervals.size() == 0) return 0;
        int leftnum = 1, lastOne = 0;
        sort(intervals.begin(), intervals.end(), myCompare);
        for (int i=1; i<(int)intervals.size(); ++i) {
            if (intervals[i].start >= intervals[lastOne].end) {
                ++leftnum;
                lastOne = i;
            }
        }
        return (int)intervals.size() - leftnum;
    }
};