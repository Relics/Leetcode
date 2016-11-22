class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans = helper(n, n);
        return ans;
    }
    vector<string> helper(int nowLen, int maxLen) {
        vector<string> res;
        if (nowLen == 1) {
            res.push_back("0"); res.push_back("1"); res.push_back("8"); 
        } else if (nowLen == 2) {
            res.push_back("69"); res.push_back("96"); res.push_back("11"); res.push_back("88");
            if (nowLen != maxLen) res.push_back("00");
        } else {
            vector<string> tempAns = helper(nowLen-2, maxLen);
            for (string str : tempAns) {
                res.push_back("6" + str + "9"); res.push_back("9" + str + "6"); 
                res.push_back("1" + str + "1"); res.push_back("8" + str + "8"); 
                if (nowLen != maxLen) res.push_back("0" + str + "0");
            }
        }
        return res;
    }
};