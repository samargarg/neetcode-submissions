class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left;
        int product = 1;
        for (int num: nums) {
            product *= num;
            left.push_back(product);
        }
        product = 1;
        vector<int> right(n);
        for (int i = n-1; i >= 0; i--) {
            product *= nums[i];
            right[i] = product;
        }
        vector<int> answer;
        for (int i = 0; i < n; i++) {
            int ans = 1;
            if (i > 0) {
                ans *= left[i-1];
            }
            if (i < n-1) {
                ans *= right[i+1];
            }
            answer.push_back(ans);
        }
        return answer;
    }
};