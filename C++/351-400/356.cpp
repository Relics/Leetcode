class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int size = (int)points.size();
        if (size <= 1) return true;
        int minf = points[0].first;
        int maxf = points[0].first;
        unordered_map<int, unordered_map<int, int>> umap;
        for (auto point : points) {
            minf = min(point.first, minf);
            maxf = max(point.first, maxf);
            ++umap[point.second][point.first];
        }
        double line = minf + (maxf - minf) / 2.0;
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            unordered_map<int, int>& temp = it->second;
            for (auto it2 = temp.begin(); it2 != temp.end(); ++it2) {
                int opposite = (int)(line * 2 - it2->first);
                if (!temp.count(opposite)) {
                    return false;
                }
            }
        }
        return true;
    }
};