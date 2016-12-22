class UF {
public:
    vector<int> pa;
    // ini
    UF(int n) {
        for (int i=0; i<n; ++i) {pa.push_back(i);}
    }
    // find
    int find(int i) {
        if (i == pa[i]) return i;
        else {
            pa[i] = find(pa[i]);
            return pa[i];
        }
    }
    // union
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        pa[ry] = rx;
    }
};

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        UF uf(n);
        int counts = 0;
        for (auto p : edges) {
            int r1 = uf.find(p.first);
            int r2 = uf.find(p.second);
            if (r1 == r2) continue;
            uf.merge(p.first, p.second);
            ++counts;
        }
        return n - counts;
    }
};