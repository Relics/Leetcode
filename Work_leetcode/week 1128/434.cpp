class Solution {
public:
    vector<string> split(string s, char delim) {
        string temp;
        stringstream ss(s);
        vector<string> res;
        while(getline(ss, temp, delim)) res.push_back(temp);
        return res;
    }
    int countWords(string s) {
        auto v = split(s, ' ');
        int counts = 0;
        for (auto s : v)
            if (s != "") ++ counts;
        return counts;
    }
};