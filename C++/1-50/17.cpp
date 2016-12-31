class Solution {
private:
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        int size = (int)digits.size();
        vector<string> ans;
        if (size == 0) return ans;
        helper(0, size, "", digits, ans);
        return ans;
    }
    void helper(int start, int size, string now, string digits, vector<string>& ans) {
        if (start >= size) {
            ans.push_back(now);
            return;
        }
        int index = digits[start] - '0';
        string candidate = v[index];
        if (candidate == "") {
            helper(start+1, size, now, digits, ans);
        } else {
            for (auto ch : candidate) {
                helper(start+1, size, now+ch, digits, ans);
            }
        }
    }
};