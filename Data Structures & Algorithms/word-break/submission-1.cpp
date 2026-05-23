#include <bits/stdc++.h>
class Solution {

    string s_;
    vector<string> wordDict_;

    int dp[210];

    bool calc(int start) {
        if (start == s_.size()) {
            return true;
        }
        if (dp[start] != -1) {
            return dp[start];
        }
        for (int i = 1; i <= 20; i++) {
            if (start+i > s_.size()) {
                break;
            }
            for (int j = 0; j < wordDict_.size(); j++) {
                if (wordDict_[j] == s_.substr(start, i)) {
                    bool this_ans = calc(start+i);
                    if (this_ans) {
                        dp[start] = true;
                        return true;
                    }
                }
            }
            
        }
        dp[start] = false;
        return dp[start];
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        wordDict_ = wordDict;
        s_ = s;
        return calc(0);
    }
};
