class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int answer = 0;
        while (i < j) {
            int l_h = height[i];
            int r_h = height[j];
            answer = max(answer, min(l_h, r_h)*(j-i));
            if (l_h > r_h) {
                j--;
            } else if (l_h < r_h) {
                i++;
            } else {
                i++;
                j--;
            }
        }
        return answer;
    }
};