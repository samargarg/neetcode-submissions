class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; i++) {
            int j = i+1;
            int k = n-1;
            while (j < k) {
                if (nums[i]+nums[j]+nums[k] > 0) {
                    while (j < k && nums[k-1] == nums[k]) {
                        k--;
                    }
                    k--;
                } else if (nums[i]+nums[j]+nums[k] < 0) {
                    while (j < k && nums[j+1] == nums[j]) {
                        j++;
                    }
                    j++;
                } else {
                    answer.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    while (j < k && nums[j+1] == nums[j]) {
                        j++;
                    }
                    j++;
                    while (j < k && nums[k-1] == nums[k]) {
                        k--;
                    }
                    k--;
                }
            }
            while (i+1 < n-2 && nums[i+1] == nums[i]) {
                i++;
            }
        }
        return answer;
    }
};