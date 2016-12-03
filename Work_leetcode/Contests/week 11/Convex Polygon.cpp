class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int size = (int)points.size();
        assert(size >= 3);
        for (int i=0; i<size-1; ++i) {
            if (!judgeOneEdge(points, i, i+1))
                return false;
        }
        return true;
    }
    bool judgeOneEdge(vector<vector<int>>& points, int p1, int p2) {
        int size = (int)points.size();
        int x1 = points[p1][0], y1 = points[p1][1];
        int x2 = points[p2][0], y2 = points[p2][1];
        int a = y2-y1, b = x1 - x2, c = y1*(x2-x1) - x1*(y2 - y1);
        int x3, y3;
        if (p1 != 0 && p2 != 0) {
            x3 = points[0][0], y3 = points[0][1];
        } else if (p1 != 1 && p2 != 1) {
            x3 = points[1][0], y3 = points[1][1];
        } else {
            x3 = points[2][0], y3 = points[2][1];
        }
        int temp = a * x3 + b * y3 + c;
        if (temp < 0) {
            for (int i=0; i<size; ++i) {
                int x = points[i][0], y = points[i][1];
                if (a*x + b*y + c > 0) return false;
            }
        } else {
            for (int i=0; i<size; ++i) {
                int x = points[i][0], y = points[i][1];
                if (a*x + b*y + c < 0) return false;
            }
        }
        return true;
    }
};