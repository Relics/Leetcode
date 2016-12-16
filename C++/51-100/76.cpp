// Solution 1
// Reference: https://github.com/Zeecoders/LeetCode/blob/master/76.%20Minimum%20Window%20Substring.md
class Solution {
public:
    string minWindow(string s, string t) {
        int sum = (int)t.size(), ssize = (int)s.size();
        unordered_map<char, int> umNeed;
        unordered_map<char, int> umActual;
        for (char ch : t) ++umNeed[ch];
        int actualSum = 0;
        string ans = "";
        bool hasUpdate = false;
        int minBegin = 0, minLen = 0;
        for (int begin = 0, end = 0; end < ssize; ++end) {
            if (umNeed.count(s[end]) == 0) continue;
            if (umNeed[s[end]] > umActual[s[end]]) ++actualSum;
            ++umActual[s[end]];
            if (actualSum == sum) {
                while (begin < end) {
                    if (umNeed.count(s[begin]) == 0) ++begin;
                    else if (umNeed[s[begin]] < umActual[s[begin]]) {--umActual[s[begin++]];}
                    else break;
                }
                if (!hasUpdate) {
                    minLen = end - begin + 1;
                    minBegin = begin;
                    hasUpdate = true;
                } else {
                    if (minLen > end-begin+1) {
                        minLen = end - begin + 1;
                        minBegin = begin;
                    }
                }
            }
        }
        return hasUpdate ? s.substr(minBegin, minLen) : "";
    }
};