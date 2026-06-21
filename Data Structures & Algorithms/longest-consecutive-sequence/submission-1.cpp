class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int i: nums) {
            s.insert(i);
        }
        vector<int> starts;
        for (int i: nums) {
            if (!s.count(i-1)) {
                starts.push_back(i);
            }
        }
        int ans = 0;
        for (int start: starts) {
            int this_ans = 1;
            int x = start+1;
            while (s.count(x)) {
                this_ans++;
                x++;
            }
            ans = max(ans, this_ans);
        }
        return ans;
    }
};
