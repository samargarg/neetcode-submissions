class Solution {

    unordered_map<char, int> orig, slid;
    int formed;
    int required;
    int n;

public:
    string minWindow(string s, string t) {
        n = s.size();
        
        for (char c: t) orig[c]++;
        required = orig.size();
        formed = 0;

        int left = 0;
        int right = -1;
        pair<int, int> ans;
        int maxi = 1e9;

        
        while (left < n) {
            while (right+1 < n && formed < required) {
                slid[s[right+1]]++;
                if (slid[s[right+1]] == orig[s[right+1]]) {
                    formed++;
                }
                right++;
            }
            while (left < n && slid[s[left]] > orig[s[left]]) {
                slid[s[left]]--;
                left++;
            }
            if (formed == required && maxi > right-left+1) {
                maxi = right-left+1;
                ans = {left, right};
            }
            slid[s[left]]--;
            left++;
            formed--;
        }
        if (maxi == 1e9) {
            return "";
        }
        return s.substr(ans.first, ans.second-ans.first+1);
    }
};