class Solution {
public:
    vector<string> permutations(string s) {
        vector<string> res;
        string ini = s;
        do {
            res.push_back(s);
            next_permutation(s.begin(), s.end());
        } while (s != ini);
        return res;
    }
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        int size = (int)s.size();
        unordered_map<char, int> umap;
        for (int i=0; i<size; ++i) {
            ++umap[s[i]];
        }
        char mid = ' ';
        string half = "";
        for (auto i : umap) {
            if (i.second & 1) {
                if (mid == ' ') {
                    mid = i.first;
                } else {
                    return res;
                }
            } 
            half.append(i.second/2, i.first);
        }
        vector<string> p = permutations(half);
        for (auto i : p) {
            string final = "";
            final += i;
            if (mid != ' ') final += mid;
            final += string(i.rbegin(), i.rend());
            res.push_back(final);
        }
        return res;
    }
};