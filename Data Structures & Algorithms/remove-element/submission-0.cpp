class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                k--;
            }
        }
        vector<int> pos;
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] != val) {
                pos.push_back(i);
            }
        }
        int p = 0;
        for (int i = 0; i < k; i++) {
            if (nums[i] == val) {
                nums[i] = nums[pos[p]];
                p++;
            }
        }
        return k;
    }
};