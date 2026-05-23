class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n-1;
        while (i < j) {
            int s = numbers[i]+ numbers[j];
            if (s < target) {
                i++;
            } else if (s > target) {
                j--;
            } else {
                return vector<int>{i+1, j+1};
            }
        }
        return vector<int>{-1, -1};
    }
};