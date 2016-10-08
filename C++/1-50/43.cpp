class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int size1 = (int)num1.size();
        int size2 = (int)num2.size();
        string ans(size1 + size2, '0');
        for (int i=0; i<size1; ++i) {
            int carry = 0;
            int belowNum = num1[i] - '0';
            for (int j=0; j<size2; ++j) {
                int exist = ans[i + j] - '0';
                int aboveNum = num2[j] - '0';
                int temp = aboveNum * belowNum + exist + carry;
                ans [i + j] = temp % 10 + '0';
                carry = temp / 10;
            }
            if (carry >= 0) ans[i + size2] = (char)(carry + '0');
        }
        reverse (ans.begin(), ans.end());
        auto index = ans.find_first_not_of('0');
        return index == string::npos ? "0" : ans.substr(index);
    }
};