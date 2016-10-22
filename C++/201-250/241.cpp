class Solution {
private: 
    unordered_map<string, vector<int>> umap;
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        if (umap.count(input)) {
            return umap[input];
        } else {
            for (int i=0; i<(int)input.size(); ++i) {
                if (input[i] == '*' || input[i] == '-' || input[i] == '+') {
                    auto subresult1 = diffWaysToCompute(input.substr(0, i));
                    auto subresult2 = diffWaysToCompute(input.substr(i+1));
                    for (int x:subresult1) {
                        for (int y:subresult2) {
                            if (input[i] == '*')
                                result.push_back(x*y);
                            else if (input[i] == '-')
                                result.push_back(x-y);
                            else
                                result.push_back(x+y);
                        }
                    }
                }
            }
        }
        if (result.empty()) result.push_back(atoi(input.c_str()));
        umap[input] = result;
        return result;
    }
};