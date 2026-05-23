class Solution {
    int n;

    vector<int> nums_;
    bool check(int x) {
        return nums_[x] < nums_[0];
    }

public:
    int search(vector<int>& nums, int target) {
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
        cout << ans << "\n";
        
        auto itr = lower_bound(nums.begin()+ans, nums.end(), target);
        if (itr != nums.end() && *itr == target) {
            cout << *itr << "\n";
            return distance(nums.begin(), itr);
        }

        itr = lower_bound(nums.begin(), nums.begin()+ans, target);
        if (itr != nums.begin()+ans && *itr == target) {
            // cout << *itr << "\n";
            return distance(nums.begin(), itr);
        }
        return -1;
    }
};