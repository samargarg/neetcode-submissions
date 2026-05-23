class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last_p = n-1;
        for (int i = n-2; i >= 0; i--) {
            if (i + nums[i] >= last_p) {
                last_p = i;
            }
        }
        return last_p == 0;
    }
};