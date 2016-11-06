class Solution {
public:
    vector<string> split(string s, char separator) {
        vector<string> res;
        int begin = 0;
        int size = (int)s.size();
        for (int i=0; i<size; ++i) {
            if (s[i] == separator) {
                string temp = s.substr(begin, i-begin);
                if (temp != "") res.push_back(temp);
                begin = i+1;
            }
        }
        string temp = s.substr(begin);
        if (temp != "") res.push_back(temp);
        return res;
    }
    int lengthLongestPath(string input) {
        int size = (int)input.size();
        if (size == 0) return 0;
        else {
            vector<string> ss = split(input, '\n');
            stack<int> store;
            int maxLength = 0;
            int currentLength = 0;
            for (auto s : ss) {
                int tabs = 0;
                while (s[tabs] == '\t') ++tabs;
                while (tabs < store.size()) {
                    int temp = store.top();
                    currentLength -= temp;
                    store.pop();
                }
                string remain = s.substr(tabs);
                if (remain.find('.') != string::npos) maxLength = max(maxLength, currentLength + (int)remain.size());
                else {
                    currentLength += (int)remain.size() + 1;
                    store.push((int)remain.size() + 1);
                }
            }                
            return maxLength;
        }
    }
};