class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_len = 0;
        int max_l = -1;
        int max_r = -1;
        for (int i = 0; i < n; i++) {
            int i_left = i;
            int i_right = i;
            while (i_left-1 >= 0 && i_right+1 < n && s[i_left-1] == s[i_right+1]) {
                i_left--;
                i_right++;
            }
            if (i_right - i_left+1 > max_len) {
                max_len = i_right - i_left+1;
                max_l = i_left;
                max_r = i_right;
            }
            if (i+1 == n) {
                continue;
            }
            i_left = i+1;
            i_right = i;
            while (i_left-1 >= 0 && i_right+1 < n && s[i_left-1] == s[i_right+1]) {
                i_left--;
                i_right++;
            }
            if (i_right - i_left+1 > max_len) {
                max_len = i_right - i_left+1;
                max_l = i_left;
                max_r = i_right;
            }
        }
        return s.substr(max_l, max_len);
    }
};
