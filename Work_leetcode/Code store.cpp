class Solution {
public:
    int compress(vector<char>& str) {
        if ((int)str.size() == 0) return 0;
        if ((int)str.size() == 1) return 1;
        int ans = 0;
        int changeIndex = 0;
        int counts = 1;
        int size = (int)str.size();
        for (int i=1; i<size; ++i) {
            if (str[i] == str[i-1]) {
                ++counts;
            } else {
                if (counts > 1) {
                    str[changeIndex] = str[i-1];
                    string temp = to_string(counts);
                    for (int j=0; j<(int)temp.size(); ++j) {
                        str[changeIndex+j+1] = temp[j];
                    }
                    counts = 1;
                    changeIndex = changeIndex+(int)temp.size()+1;
                    ans += (int)temp.size()+1;
                } else {
                    str[changeIndex] = str[i-1];
                    changeIndex = changeIndex+1;
                    ++ans;
                }
            }
        }
        if (str[size-1] == str[size-2]) {
            str[changeIndex] = str[size-1];
            string temp = to_string(counts);
            for (int j=0; j<(int)temp.size(); ++j) {
                str[changeIndex+j+1] = temp[j];
            }
            ans += (int)temp.size()+1;
        } else {
            str[changeIndex] = str[size-1];
            ++ans;
        }
        return ans;
    }
};