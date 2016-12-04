// Solution 1
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        if (word == "") return {""};
        ans = helper(word, 0);
        return ans;
    }
    vector<string> helper(string word, int begin) {
        int size = (int)word.size();
        vector<string> ans;
        if (begin >= size) return {""};
        for (int i=begin; i<size; ++i) {
            vector<string> subans = helper(word, i+2);
            string temp = to_string(i-begin+1);
            if (i < size-1) temp += word[i+1];
            for (auto str : subans) {
                ans.push_back(temp + str);
            }
        }
        vector<string> subans = helper(word, begin+1);
        string temp = word.substr(begin, 1);
        for (auto str : subans) {
            ans.push_back(temp + str);
        }
        return ans;
    }
};

// Solution 2
class Solution {
public:
    void dfs(vector<string>& res, string word, string tempRes, int start) {
        int wsize = (int)word.size();
        if (start >= wsize) {res.push_back(tempRes); return;}
        dfs(res, word, tempRes+word[start], start+1);
        for (int i=start; i<wsize; ++i) {
            string num = to_string(i-start+1);
            if (i+1 < wsize)
                dfs(res, word, tempRes+num+word[i+1], i+2);
            else res.push_back(tempRes+num);
        }
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        if ((int)word.size() == 0) return {""};
        dfs(res, word, "", 0);
        return res;
    }
};