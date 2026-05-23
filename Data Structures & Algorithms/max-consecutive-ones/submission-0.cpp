class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = 0;
        int Maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                m++;
            } else {
                Maxi = max(Maxi, m);
                m = 0;
            }
        }
        Maxi = max(Maxi, m);
        return Maxi;
    }
};