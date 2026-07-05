class Solution {

public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int ans = 1e9;
        for (int i = 0; i < n-k; i++) {
            sum += cardPoints[i];
        }
        ans = min(ans, sum);
        cout << ans << "\n";
        for (int i = n-k; i < n; i++) {
            sum += cardPoints[i];
            sum -= cardPoints[i-n+k];
            ans = min(ans, sum);
            cout << ans << "\n";
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += cardPoints[i];
        }
        return total-ans;
    }
};