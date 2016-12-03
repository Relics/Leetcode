class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = "";
        for (auto str : strs) {
            ans += to_string((int)str.size()) + "@" + str;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int head = 0, size = (int)s.size();
        while (head < size) {
            int atPos = s.find('@', head);
            int strSize = stoi(s.substr(head, atPos-head));
            ans.push_back(s.substr(atPos+1, strSize));
            head = atPos + strSize + 1;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));