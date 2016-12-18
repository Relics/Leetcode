class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        vector<int> word1ShowUp;
        vector<int> word2ShowUp;
        int size = (int)words.size();
        for (int i=0; i<size; ++i) {
            if (words[i] == word1) word1ShowUp.push_back(i);
            if (words[i] == word2) word2ShowUp.push_back(i);
        }
        int size1 = (int)word1ShowUp.size(), size2 = (int)word2ShowUp.size(), a = 0, b = 0;
        int ans = INT_MAX;
        while (a < size1 && b < size2) {
            if (word1ShowUp[a] != word2ShowUp[b]) {
                ans = min(ans, abs(word1ShowUp[a] - word2ShowUp[b]));
            }
            if (word1ShowUp[a] < word2ShowUp[b]) {
                ++a;
            } else {
                ++b;
            }
        }
        return ans;
    }
};