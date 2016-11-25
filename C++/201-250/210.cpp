// bfs
class Solution {
private:
    vector<unordered_set<int>> makeGraph(int size, vector<pair<int, int>>& pairs) {
        vector<unordered_set<int>> graph(size);
        for (auto p : pairs) {
            graph[p.second].insert(p.first);
        }
        return graph;
    }
    vector<int> calIndegree(int size, vector<unordered_set<int>>& graph) {
        vector<int> indegree(size, 0);
        for (auto node : graph) {
            for (auto n : node) {
                ++indegree[n];
            }
        }
        return indegree;
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> indegree = calIndegree(numCourses, graph);
        vector<int> path;
        while (true) {
            int i = 0;
            for (; i<numCourses; ++i) {
                if (indegree[i] == 0) break;
            }
            if (i == numCourses) {
                if ((int)path.size() == numCourses) return path;
                else return {};
            } else {
                indegree[i] = -1;
                path.push_back(i);
                for (auto n : graph[i]) {
                    --indegree[n];
                }
            }
        }
    }
};