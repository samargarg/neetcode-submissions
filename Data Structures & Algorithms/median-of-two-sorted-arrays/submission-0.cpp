class Solution {
    vector<int> nums1_;
    vector<int> nums2_;

    int m, n;

    bool check(int x, int k) {
        auto itr = lower_bound(nums1_.begin(), nums1_.end(), x);
        int a = distance(nums1_.begin(), itr);

        itr = lower_bound(nums2_.begin(), nums2_.end(), x);
        int b = distance(nums2_.begin(), itr);
        return a+b <= k;
    }


public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        nums1_ = nums1;
        nums2_ = nums2;

        int low = -1e6;
        int high = 1e6;
        int answer = -1e6;
        while (low <= high) {
            int mid = (low+high)/2;
            if (check(mid, (m+n-1)/2)) {
                low = mid+1;
                answer = mid;
            } else {
                high = mid-1;
            }
        }
        if ((m+n)%2) {
            return answer;
        } else {
            int low = -1e6;
            int high = 1e6;
            int answer2 = -1e6;
            while (low <= high) {
                int mid = (low+high)/2;
                if (check(mid, (m+n)/2)) {
                    low = mid+1;
                    answer2 = mid;
                } else {
                    high = mid-1;
                }
            }
            return (((double) answer)+answer2)/2;
        }
    }
};