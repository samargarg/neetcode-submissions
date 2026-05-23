class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for (string s: strs) {
            ans += "/:";
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '/') {
                    ans += s[i];
                }
                ans += s[i];
            }
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        if (s.empty()) {
            return vector<string>{};
        }
        s = s.substr(2);
        cout << s << "\n";
        vector<string> ans;
        string t;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '/') {
                if (s[i+1] == ':') {
                    ans.push_back(t);
                    t = "";
                    i++;
                } else {
                    t += '/';
                    i++;
                }
            } else {
                t += s[i];
            }
        }
        ans.push_back(t);
        return ans;
    }
};
