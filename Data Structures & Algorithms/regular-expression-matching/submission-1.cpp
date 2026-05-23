class Solution {
    string st;
    string pt;
    int calc(int i, int j) {
        if (j < 0) {
            return i < 0;
        }

        if (pt[j] == '.') {
            return calc(i-1, j-1);
        } else if (pt[j] == '*') {
            if (i >= 0 && (pt[j-1] == st[i] || pt[j-1] == '.')) {
                if (calc(i-1, j)) {
                    return true;
                }
            }
            if (calc(i, j-2)) {
                return true;
            }
            return false;
        } else if (i >= 0 && st[i] == pt[j]) {
            return calc(i-1, j-1);
        } else {
            return false;
        }
    }

public:
    bool isMatch(string s, string p) {
        st = s;
        pt = p;
        return calc(s.size()-1, p.size()-1);
    }
};
