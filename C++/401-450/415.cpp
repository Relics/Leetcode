class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1 = (int)num1.size(), i = size1-1;
        int size2 = (int)num2.size(), j = size2-1;
        int carry = 0;
        string res = "";
        while (i>=0 || j>=0 || carry>0) {
            int sum = 0;
            if (i>=0) {
                sum += num1[i]-'0';
                --i;
            }
            if (j>=0) {
                sum += num2[j]-'0';
                --j;
            }
            sum += carry;
            res = to_string (sum % 10) + res;
            carry = sum / 10;
        }
        return res;
    }
};