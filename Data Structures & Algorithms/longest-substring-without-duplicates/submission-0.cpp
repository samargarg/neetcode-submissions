class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = -1;
        int answer = 0;
        int n = s.size();
        set<char> unique;
        while (left < n) {
            while (right+1 < n && unique.count(s[right+1]) == 0) {
                unique.insert(s[right+1]);
                right++;
            }
            answer = max(answer, right-left+1);
            if (right >= left) {
                unique.erase(s[left]);
            } else {
                right++;
            }
            left++;
        }
        return answer;
    }
};