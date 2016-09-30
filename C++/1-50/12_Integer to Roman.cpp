class Solution {
    string THOUS[4]={"","M","MM","MMM"};
    string HUNDS[10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string TENS[10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string ONES[10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
public:
    string intToRoman(int num) {
        string res;
        res += THOUS[num/1000];
        res += HUNDS[num/100%10];
        res += TENS[num/10%10];
        res += ONES[num%10];
        return res;
    }
};
