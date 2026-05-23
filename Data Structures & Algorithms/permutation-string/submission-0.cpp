class Solution {
    vector<int> orig;
    vector<int> slid;
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();
        orig.resize(26, 0);
        slid.resize(26, 0);
        for (char c: s1) {
            orig[c - 'a']++;
        }
        int left = 0;
        int right = -1;
        while (left < n-m+1) {
            while (right+1 < n && slid[s2[right+1] - 'a'] < orig[s2[right+1] - 'a']) {
                slid[s2[right+1] - 'a']++;
                right++;
            }
            if (right-left+1 == m) {
                return true;
            }
            if (right >= left) {
                slid[s2[left] - 'a']--;
            } else {
                right++;
            }
            left++;
        }
        return false;
    }
};
