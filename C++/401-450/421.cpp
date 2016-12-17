class TrieNode {
public:
    TrieNode* child[2];
    TrieNode() {
        memset(child, NULL, sizeof(child));
    }
};

class TrieTree {
private:
    TrieNode* root;
public:    
    TrieTree() {
        root = new TrieNode();
    }
    void insert(int num) {
        TrieNode* current = root;
        for (int i=30; i>=0; --i) {
            int bit = num & (1 << i);
            int flag = bit == 0 ? 0 : 1;
            if (current -> child[flag] == NULL) {
                current -> child[flag] = new TrieNode();
            }
            current = current -> child[flag];
        }
    }
    int findMaxPossibleXOR(int num) {
        int bestMatch = 0;
        TrieNode* current = root;
        for (int i=30; i>=0; --i) {
            int bit = num & (1 << i);
            int flag = bit == 0 ? 0 : 1;
            if (current -> child[1-flag]) {
                bestMatch += ((1-flag) << i);
                current = current -> child[1-flag];
            } else {
                bestMatch += (flag << i);
                current = current -> child[flag];
            }
        }
        return bestMatch ^ num;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if ((int)nums.size() < 2) return 0;
        TrieTree t;
        for (auto num : nums) {
            t.insert(num);
        }
        int ans = -1;
        for (auto num : nums) {
            ans = max(ans, t.findMaxPossibleXOR(num));
        }
        return ans;
    }
};