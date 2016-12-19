class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int size = (int)s.size();
        vector<string> ans;
        for (int a=0; a<=3; ++a)
        for (int b=0; b<=3; ++b)
        for (int c=0; c<=3; ++c)
        for (int d=0; d<=3; ++d)
            if (a + b + c + d == size) {
                string aa = s.substr(0, a);
                string bb = s.substr(a, b); 
                string cc = s.substr(a+b, c);
                string dd = s.substr(a+b+c); 
                if (aa != "" && bb != "" && cc != "" && dd != "") {
                    int aaa = stoi(aa);
                    int bbb = stoi(bb);
                    int ccc = stoi(cc);
                    int ddd = stoi(dd);
                    if (aaa>=0 && aaa<=255 && bbb>=0 && bbb<=255 && ccc>=0 && ccc<=255 && ddd>=0 && ddd<=255) {
                        string temp = to_string(aaa) + "." + to_string(bbb) + "." + to_string(ccc) + "." + to_string(ddd);
                        if ((int)temp.size() == size+3)
                            ans.push_back(temp);
                    }
                }
            }
        return ans;
    }
};