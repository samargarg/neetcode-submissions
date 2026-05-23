class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int temp = 1;
        int answer = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]+1) {
                temp++;
                answer = max(answer, temp);
            } else if (nums[i] == nums[i-1]) {
                continue;
            } else {
                temp = 1;
            }
        }
        return answer;
    }
};