// The negative num can't use while loop
// 处理的过程就是每次获取最低4位，将其对应的16进制表示添加到结果字符串的开头。
// 关键的一点是，进行循环移位时，需要把数转为无符号数进行移位，因为右移操作符添加的值依赖于运算对象的类型，如果是无符号数，则添加0，否则添加符号位的副本或是0，根据具体环境而定。
// 这里我们希望的是添加0，以便用于判断循环结束，所以进行了类型转换。
class Solution {
public:
    string toHex(int num) {
        string ans = "";
        while (num) {
            int temp = num&15;
            if (temp>=0 && temp<=9) ans = char(temp + '0') + ans;
            else if (temp >=10) ans = char(temp - 10 + 'a') + ans;
            num = (unsigned)num >> 4;
        }
        auto index = ans.find_first_not_of('0');
        return index == string::npos ? "0" : ans.substr(index);
    }
};

// Solution 2
class Solution {
public:
    string toHex(int num) {
        string convert = "0123456789abcdef";
        string ans = "";
        for(int i=0; i<8; ++i) {
            ans = convert[num&15] + ans;
            num >>= 4;
        }
        auto index = ans.find_first_not_of('0');
        return index == string::npos ? "0" : ans.substr(index);
    }
};