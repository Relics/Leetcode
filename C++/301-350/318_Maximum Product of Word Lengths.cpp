typedef long long ll;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = (int)words.size();
        vector<int> flag(size, 0);
        for (int i=0; i<size; ++i){
            for (int j=0; j<(int)words[i].size(); ++j){
                flag[i] |= 1 << (words[i][j] - 'a');
            }
        }
        ll ans = 0;
        for (int i=0; i<size; ++i){
            for (int j=i+1; j<size; ++j){
                if (!(flag[i] & flag[j]) && ((ll)words[i].size() * (ll)words[j].size() > ans))
                    ans = (ll)words[i].size() * (ll)words[j].size();
            }
        }
        return ans;
    }
};