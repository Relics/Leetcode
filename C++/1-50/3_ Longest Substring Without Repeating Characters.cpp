// Very Smart Solution!
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int start=-1;
        vector<int> dict(256, -1);
        for (int i=0; i<s.size(); ++i) {
            if (dict[s[i]]>start) {
                start=dict[s[i]];
            }
            dict[s[i]]=i;
            ans=max(ans, i-start);
        }
        return ans;
    }
};