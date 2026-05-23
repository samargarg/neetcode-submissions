class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        int n = nums.size();
        vector<int> ans(n-k+1);
        for (int i = 0; i < k; i++) {
            int t = nums[i];
            while (d.size() && nums[d.front()] <= t) {
                d.pop_front();
            }
            d.push_front(i);
        }
        ans[0] = nums[d.back()];
        
        for (int i = 1; i < n-k+1; i++) {
            int t = nums[i+k-1];
            while (d.size() && nums[d.front()] <= t) {
                d.pop_front();
            }
            d.push_front(i+k-1);
            if (d.back() == i-1) {
                d.pop_back();
            }
            ans[i] = nums[d.back()];
        }
        return ans;
    }
};