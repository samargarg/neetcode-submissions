class Solution {
public:
    bool checkValidString(string s) {

        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            if (m[')'] > m['('] + m['*']) {
                return false;
            }
        }
        m.clear();
        for (int i = s.size()-1; i >= 0; i--) {
            m[s[i]]++;
            if (m['('] > m[')'] + m['*']) {
                return false;
            }
        }
        return true;
    }
};