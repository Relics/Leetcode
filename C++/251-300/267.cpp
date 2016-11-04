class Solution {
public:
    vector<string> generatePalindromes(string s) {
        int size = (int)s.size();
        unordered_map<char, int> umap;
        vector<string> res;
        for (int i=0; i<size; ++i) {
            ++umap[s[i]];
        }
        char mid = ' ';
        string ini = "";
        for (auto i : umap) {
            if (i.second & 1) {
                if (mid == ' ') {
                    mid = i.first;
                    --i.second;
                } else {
                    return res;
                }
            }
            ini.append(i.second /2, i.first);
        }
        solve(res, ini, 0, mid);
        return res;
    }
    void solve(vector<string>& res, string& ini, int start, char mid) {
        int size = (int)ini.size();
        // Bug 1 here because we must use >= to represent the terminate condition, not ==
        // because >= is also illegal
        if (start >= size - 1) {
            string final = "";
            if (mid != ' ') {
                // Bug 2 here use the final += ini + mid + reverse(ini.begin(), ini.end())
                // But it's illegal since reverse return void.
                final += ini + mid + string(ini.rbegin(), ini.rend());
            } else {
                final += ini + string(ini.rbegin(), ini.rend());
            }
            res.push_back(final);
        } else {
            unordered_set<char> isSwapped;
            for (int i=start; i<size; ++i) {
                if (isSwapped.find(ini[i]) == isSwapped.end()) {
                    isSwapped.insert(ini[i]);
                    swap(ini[start], ini[i]);
                    solve(res, ini, start+1, mid);
                    swap(ini[start], ini[i]);
                }
            }
        }
    }
};