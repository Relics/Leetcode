class Solution {
public:
    int getMaxBalanceIndex(vector<int> amount) {
        int size = (int)amount.size(), res = 0;
        for (int i=1; i<size; ++i) {
            if (amount[i] > amount[res]) res = i;
        }
        return res;
    }
    int getMinBalanceIndex(vector<int> amount) {
        int size = (int)amount.size(), res = 0;
        for (int i=1; i<size; ++i) {
            if (amount[i] < amount[res]) res = i;
        }
        return res;
    }
    int solve(vector<int> amount) {
        int ans = 0;
        while (true) {
            int maxBalanceIn = getMaxBalanceIndex(amount);
            int minBalanceIn = getMinBalanceIndex(amount);
            if (amount[maxBalanceIn] == 0 && amount[minBalanceIn] == 0) return ans;
            int absMinBalance = min(amount[maxBalanceIn], -amount[minBalanceIn]);
            amount[maxBalanceIn] -= absMinBalance;
            amount[minBalanceIn] += absMinBalance;
            ++ ans;
        }
        return ans;
    }
    int minTransfers(vector<vector<int>>& trans) {
        int size = (int)trans.size();
        if (size == 0) return 0;
        unordered_map<int, unordered_map<int, int>> graph;
        unordered_set<int> users;
        int maxUser = 0;
        for (int i=0; i<size; ++i) {
            int a = trans[i][0], b = trans[i][1], c = trans[i][2];
            users.insert(a); users.insert(b);
            maxUser = max(max(maxUser, a), b);
            graph[a][b] += c;
        }
        int usersize = max((int)users.size(), maxUser+1);
        vector<int> amount(usersize, 0); // Everybody's balance
        // Convert it to the amount array
        for (int i=0; i<usersize; ++i) {
            for (int j=0; j<usersize; ++j) {
                amount[i] += graph[j][i] - graph[i][j];
            }
        }
        // Solve the porblem
        return solve(amount);
    }
};
