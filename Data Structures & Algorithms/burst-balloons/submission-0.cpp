class Solution {
    vector<int> nums_;
    int calc(int i, int j) {
        if (j-i == 1) {
            return 0;
        }
        int ans = 0;
        for (int k = i+1; k < j; k++) {
            ans = max(ans, calc(i, k) + calc(k, j) + nums_[i]*nums_[j]*nums_[k]);
        }
        cout << "i: " << i << ", j: " << j << ", ans: " << ans << "\n";
        return ans;
    }

public:
    int maxCoins(vector<int>& nums) {
        nums_ = nums;
        nums_.insert(nums_.begin(), 1);
        nums_.push_back(1);
        for (int i = 0; i < nums_.size(); i++) {
            cout << nums_[i] << " ";
        }
        cout << "\n";
        return calc(0, nums_.size()-1);
    }
};

