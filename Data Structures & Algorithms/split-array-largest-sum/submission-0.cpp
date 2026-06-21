class Solution {

    bool check(int x, vector<int>& nums, int k) {
        int current = 0;
        k--;
        for (int num: nums) {
            if (num > x) {
                return false;
            }
            if (current + num <= x) {
                current += num;
            } else {
                if (!k) {
                    return false;
                }
                current = num;
                k--;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 1e9;
        int ans = 1e9;
        while (low <= high) {
            int mid = (low+high)/2;
            if (check(mid, nums, k)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};