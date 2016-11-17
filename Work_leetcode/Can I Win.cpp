class Solution {
private:
    unordered_map<int, bool> isUsed;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        bool ans = false;
        for (int i=1; i<=maxChoosableInteger; ++i) isUsed[i] = false;
        return helper(desiredTotal);
    }
    bool helper(int disiredTotal) {
        for (auto m : isUsed) {
            if (!m.second) {
                if (m.first > disiredTotal) return true;
                m.second = true;
                bool tempAns = helper(disiredTotal - m.first);
                if (!tempAns) return true;
                m.second = false;
            }
        }
        return false;
    }
};