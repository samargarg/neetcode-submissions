class Solution {

    bool check(int x, vector<int>& piles, int h) {
        int total = 0;
        for (int pile: piles) {
            total += ((pile+x-1)/x);
        }
        return total <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1e9;
        int ans = 1e9;
        while (low <= high) {
            int mid = (low+high)/2;
            if (check(mid, piles, h)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};
