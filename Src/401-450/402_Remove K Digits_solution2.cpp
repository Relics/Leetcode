class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int keep=(int)num.size()-k;
        for (int i=0; i<(int)num.size(); ++i){
            while(!res.empty() && res.back()>num[i] && k>0){
                res.pop_back();
                --k;
            }
            res.push_back(num[i]);
        }
        // res.erase(keep, string::npos); 
        res.resize(keep);
       	int i=0;
       	while(i<(int)res.size()-1 && res[i]=='0') ++i;
       	res.erase(0, i);
       	return res=="" ? "0" : res;
    }
};