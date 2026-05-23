class Solution {

    vector<int> piles_;
    int h_;

    bool check(int k) {
        long long total = 0;
        for (int pile: piles_) {
            total += (-1LL + pile+k)/k;
        }
        return total <= h_;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        piles_ = piles;
        h_ = h;
        int low = 1;
        int high = 1e9;
        int ans = 1e9;
        while (low <= high) {
            int mid = (low+high)/2;
            if (check(mid)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};