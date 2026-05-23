class Solution {
    int n;

    vector<int> nums_;
    bool check(int x) {
        return nums_[x] < nums_[0];
    }

public:
    int findMin(vector<int>& nums) {
        n = nums.size();
        nums_ = nums;
        int low = 0;
        int high = n-1;
        int ans = 0;
        while (low <= high) {
            int mid = (low+high)/2;
            if (check(mid)) {
                high = mid-1;
                ans = mid;
            } else {
                low = mid+1;
            }
        }
        return nums_[ans];
    }
};