// http://blog.csdn.net/nomasp/article/details/51726454
typedef long long ll;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        if (denominator == 0) return "";
        string ans = "";
        bool sign = true;
        if ((numerator < 0) ^ (denominator < 0)) sign = false;
        ll n = abs((ll)numerator);
        ll d = abs((ll)denominator);
        unordered_map<ll, int> umap;
        
        if (n % d == 0) ans = to_string(n / d);
        else ans = to_string(n / d) + '.';
        
        int index = (int)ans.size();
        ll remainder = n % d;
        
        while (remainder != 0 && (umap.count(remainder) == 0)) {
            umap[remainder] = index++;
            remainder *= 10;
            ans += to_string(remainder / d);
            remainder = remainder % d;
        }
        if (remainder != 0) {
            ans.insert(umap[remainder], 1, '(');
            ans += ')';
        }
        if (!sign) return "-" + ans;
        return ans;
    }
};