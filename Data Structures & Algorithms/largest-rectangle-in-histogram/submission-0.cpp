class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> left(n, 0);
        vector<int> right(n, n-1);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                right[s.top()] = i-1;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                left[s.top()] = i+1;
                s.pop();
            }
            s.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (right[i]-left[i]+1)*heights[i]);
        }
        return ans;
    }
};