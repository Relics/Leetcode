class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int size = (int)digits.size();
        vector<string> ans;
        if (size == 0) return ans;
        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ans.push_back(""); // seed
        for (auto ch : digits) {
            int index = ch - '0';
            //if (index < 0 || index > 9) break;
            string candidate = v[index];
            if (candidate.empty()) continue;
            vector<string> temp;
            for (auto str : ans) {
                for (auto c : candidate) {
                    temp.push_back(str + c);
                }
            }
            ans = temp;
        }
        return ans;
    }
};