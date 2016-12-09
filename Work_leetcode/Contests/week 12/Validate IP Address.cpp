class Solution {
public:
    vector<string> split(string s, char delim) {
        stringstream ss(s);
        string temp;
        vector<string> output;
        while (getline(ss, temp, delim)) if(temp != "") output.push_back(temp);
        return output;
    }
    bool check4(string IP) {
        auto strs = split(IP, '.');
        if (strs.size() != 4) return false;
        for (auto str : strs) {
            if (str.size() == 0 || str.size() > 3) return false;
            if (str[0] == '0') return false;
            for (auto ch : str) {
                if (!isdigit(ch)) return false;
            }
            int temp = stoi(str);
            if (temp < 0 || temp > 255) return false;
        }
        return true;
    }
    bool check6(string IP) {
        auto strs = split(IP, ':');
        if (strs.size() != 8) return false;
        for (auto str: strs) {
            if (str.size() == 0 || str.size() > 4) return false;
            for (auto ch : str) {
                if (!isdigit(ch) && !isalpha(ch)) return false;
                if (isupper(ch)) {
                    if (ch > 'F') return false;
                } else {
                    if (ch > 'f') return false;
                }
            }
        }
        return true;
    }
    string validIPAddress(string IP) {
        if (check4(IP)) {
            return "IPv4";
        } else if (check6(IP)) {
            return "IPv6";
        } else {
            return "Neither";
        }
    }
};