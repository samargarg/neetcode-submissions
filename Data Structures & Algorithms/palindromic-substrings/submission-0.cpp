class Solution {


public:
    int countSubstrings(string s) {
        int n = s.size();
        int total = n;
        for (int i = 0; i < n; i++) {
            int i_left = i;
            int i_right = i;
            while (i_left-1 >= 0 && i_right+1 < n && s[i_left-1] == s[i_right+1]) {
                total++;
                i_left--;
                i_right++;
            }
            if (i+1 == n) {
                continue;
            }
            i_left = i+1;
            i_right = i;
            while (i_left-1 >= 0 && i_right+1 < n && s[i_left-1] == s[i_right+1]) {
                total++;
                i_left--;
                i_right++;
            }
        }
        return total;
    }
};


