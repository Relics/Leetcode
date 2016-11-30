struct myPair {
    int index1, index2;
    int sum;
    myPair(int index1, int index2, int sum) : index1(index1), index2(index2), sum(sum) {}
    bool operator < (const myPair& b) const {
        return sum > b.sum;
    }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<pair<int, int>> res;
        if (m == 0 || n == 0) return res;
        priority_queue<myPair> pq;
        pq.push(myPair(0, 0, nums1[0]+nums2[0]));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dx[2] = {0, 1}, dy[2] = {1, 0};
        visited[0][0] = true;
        while (k-- && !pq.empty()) {
            myPair temp = pq.top();
            int index1 = temp.index1, index2 = temp.index2;
            pq.pop(); visited[index1][index2] = true;
            res.push_back(make_pair(nums1[index1], nums2[index2]));
            for (int i = 0; i < 2; ++i) {
                int newindex1 = index1 + dx[i], newindex2 = index2 + dy[i];
                if (newindex1 < m && newindex2 < n && !visited[newindex1][newindex2]) {
                    visited[newindex1][newindex2] = true;
                    pq.push(myPair(newindex1, newindex2, nums1[newindex1]+nums2[newindex2]));
                }
            }
        }
        return res;
    }
};