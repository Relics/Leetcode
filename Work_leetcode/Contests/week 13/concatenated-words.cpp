/*
 * created by Stomach_ache
 */

const int MAX_NODE = 50010;

bool is[MAX_NODE];
int ch[MAX_NODE][26];
int dp[MAX_NODE];

struct Trie {
    
    int tot;

    void init () {
        tot = 0;
        memset(ch[0], -1, sizeof(ch[0]));
        memset(is, false, sizeof(is));
    }

    void insert(string &s) {
        int rt = 0;
        for (char c: s) {
            int id = c - 'a';
            if (ch[rt][id] == -1) {
                ch[rt][id] = ++ tot;
                memset(ch[tot], -1, sizeof(ch[tot]));
            }
            rt = ch[rt][id];
        }
        is[rt] = true;
    }

    int search(const string &s, int i) {

        int rt = 0;
        int n = s.length();

        if (i >= n) return 1;
        if (dp[i] != -1) return dp[i];

        for (int j = i; j < n; ++ j) {
            if (i == 0 && j == n - 1) return dp[i] = 0;
            int id = s[j] - 'a';
            if (ch[rt][id] == -1) {
                return dp[i] = 0;
            }
            rt = ch[rt][id];
            if (is[rt] && search(s, j + 1)) return dp[i] = 1;
        }
        return dp[i] = 0;
    }
}tree;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        assert((int)words.size() <= 10000);
        tree.init();
        int totalSum = 0;
        for (string &word: words) {
            totalSum += (int)word.size();
            tree.insert(word);
        }
        assert(totalSum <= 600000);
        
        vector<string> ans;
        for (string &word: words) {
            if (word.length() && check(word)) ans.emplace_back(word);
        }
        
        return ans;
    }

    bool check(const string &s) {
        int n = s.length();
        
        memset(dp, -1, sizeof(int) * n);
        
        if (tree.search(s, 0) == 1) return true;
        else return false;
    }
};