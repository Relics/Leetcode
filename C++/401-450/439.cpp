class Solution {
public:
    string parseTernary(string expression) {
        stack<char> s;
        int size = (int)expression.size();
        for (int i=size-1; i>=0; --i) {
            if (expression[i] == '?') {
                char op = expression[--i];
                char num1 = s.top();
                s.pop(); // pop num1
                s.pop(); // pop :
                char num2 = s.top();
                s.pop(); // pop num2
                if (op == 'T') {
                    s.push(num1);
                } else {
                    s.push(num2);
                }
            } else {
                s.push(expression[i]);
            }
        }
        string ans(1, s.top());
        return ans;
    }
};