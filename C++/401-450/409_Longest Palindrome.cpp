class Solution {
public:
    int longestPalindrome(string s) {
        int a[52];
        memset(a, 0, sizeof(a));
        int ans=0;
        int ssize = (int)s.size();
        for (int i=0; i<ssize; ++i){
            if (s[i] >= 'a'){
                ++a[s[i]-'a'+26];
            }else{
                ++a[s[i]-'A'];
            }
        }
        bool flag=false;
        for (int i=0; i<52; ++i){
            if (a[i] & 1) {
                ans+=a[i]-1;
                flag=true;
            }else{
                ans+=a[i];
            }
        }
        if (flag) ++ans;
        return ans;
    }
};
