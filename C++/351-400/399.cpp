class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> res;
        for (int i=0; i< (int)values.size(); ++i) {
            graph[equations[i].first][equations[i].second] = values[i];
            graph[equations[i].second][equations[i].first] = 1 / values[i];
        }
        for (auto i:queries) {
            unordered_set<string> s;
            double ans = check(i.first, i.second, graph, s);
            if (ans) res.push_back(ans);
            else res.push_back(-1);
        }
        return res;
    }
    double check(string numerator, string denominator, unordered_map<string, unordered_map<string, double>> graph, unordered_set<string>& s) {
        if (graph[numerator].find(denominator) != graph[numerator].end()) return graph[numerator][denominator];
        for (auto i : graph[numerator]) {
            if (s.find(i.first) == s.end()) {
                s.insert(i.first);
                double subans = check(i.first, denominator, graph, s);
                if (subans) return i.second * subans;
            }
        }
        return 0;
    }
};