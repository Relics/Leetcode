/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct myPoint {
    int index;
    int value;
    bool isStart;
    bool isEnd;
    myPoint() {
        index = 0;
        value = 0;
        isStart = false;
        isEnd = false;
    }
    myPoint(int i, int val, bool start) {
        index = i;
        value = val;
        if (start) {isStart = true; isEnd = false;}
        else {isStart = false; isEnd = true;}
    }
    bool operator < (const myPoint& p) const {
        if (this->value != p.value)
            return this->value < p.value;
        else
            return this->isEnd;
    }
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        int size = (int)intervals.size();
        vector<int> result(size, -1);
        vector<myPoint> points;
        for (int i=0; i<size; ++i) {
            myPoint* newStartPoint = new myPoint(i, intervals[i].start, true);
            myPoint* newEndPoint = new myPoint(i, intervals[i].end, false);
            points.push_back(*newStartPoint);
            points.push_back(*newEndPoint);
        }
        sort(points.begin(), points.end());
        stack<int> indexs;
        for (int i=0; i<(int)points.size(); ++i) {
            if (points[i].isStart) {
                if (indexs.empty()) continue;
                else {
                    int remain = -1;
                    while (!indexs.empty()) {
                        if (points[i].index!=indexs.top()) {
                            result[indexs.top()] = points[i].index;
                            indexs.pop();
                        } else {
                            remain = indexs.top();
                            indexs.pop();
                        }
                    }
                    if (remain != -1)
                        indexs.push(remain);
                }
            } else {
                indexs.push(points[i].index);
            }
        }
        return result;
    }
};

