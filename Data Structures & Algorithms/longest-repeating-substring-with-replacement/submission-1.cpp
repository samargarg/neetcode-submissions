class Solution {
    unordered_map<char, int> m;



public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int answer = 0;
        int left = 0;
        int right = -1;
        int highest_freq = 0;
        while (left < n) {
            while (right+1 < n && (m.size() == 0 || right+1-left-highest_freq < k || m[s[right+1]] == highest_freq)) {
                if (m[s[right+1]] == highest_freq) {
                    highest_freq++;
                }
                m[s[right+1]]++;
                right++;
            }
            answer = max(answer, right-left+1);
            m[s[left]]--;
            if (m[s[left]] == 0) {
                m.erase(s[left]);
            }
            highest_freq = 0;
            for (auto [c, f]: m) {
                highest_freq = max(highest_freq, f);
            }
            left++;
        }
        return answer;
    }
};
