class Solution {
    using ii = pair<int, int>;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num: nums) {
            m[num]++;
        }
        vector<ii> s;
        for (auto [num, freq]: m) {
            s.push_back({-freq, num});
        }
        sort(s.begin(), s.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(s[i].second);
        }
        return ans;
    }
};