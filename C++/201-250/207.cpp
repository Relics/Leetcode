// Reference
// https://discuss.leetcode.com/topic/17273/18-22-lines-c-bfs-dfs-solutions
// BFS
class Solution {
private:
    vector<unordered_set<int>> makeGraph(int size, vector<pair<int, int>>& pairs, vector<int>& indegree) {
        vector<unordered_set<int>> graph(size);
        for (auto p : pairs) {
            if (graph[p.second].count(p.first) == 0) ++indegree[p.first];
            graph[p.second].insert(p.first);
        }
        return graph;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites, indegree);
        int len = numCourses;
        while (len--) {
            int i=0;
            for (; i<numCourses; ++i) {
                if (indegree[i] == 0) break;
            }
            if (i == numCourses) return false;
            indegree[i] = -1;
            for (auto n : graph[i]) --indegree[n];
        }
        return true;
    }
};


// DFS
class Solution {
private:
    vector<unordered_set<int>> makeGraph(int size, vector<pair<int, int>>& pairs) {
        vector<unordered_set<int>> graph(size);
        for (auto p : pairs) 
            graph[p.second].insert(p.first);
        return graph;
    }
    bool dfs(vector<unordered_set<int>> graph, int index, vector<bool>& path, vector<bool>& visited) {
        if (visited[index]) return false;
        visited[index] = path[index] = true;
        for (auto son : graph[index]) {
            if (path[son] || dfs(graph, son, path, visited)) {
                return true;
            }
        }
        path[index] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
        vector<bool> path(numCourses, false), visited(numCourses, false);
        for (int i=0; i<numCourses; ++i) {
            if (!visited[i] && dfs(graph, i, path, visited)) return false;
        }
        return true;
    }
};


// Using list!
// List is way better than the vector, when the algorithm has many erase operations
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, list<int>> umap;
        for (auto i : prerequisites) {
            umap[i.first].push_back(i.second);
        }
        while (umap.size() > 0) {
            bool update = false;
            for (auto i : umap) {
                for (auto j = i.second.begin(); j != i.second.end(); ++j) {
                    if (umap.count(*j) == 0) {
                        i.second.erase(j);
                        update = true;
                    }
                }
                if (i.second.size() == 0) umap.erase(i.first);
            }
            if (!update) break;
        }
        if (umap.size() == 0) return true;
        else return false;
    }
};