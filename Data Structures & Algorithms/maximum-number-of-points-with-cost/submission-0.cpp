using lli = long long;
class Solution {


public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        lli ans = 0;
        vector<lli> rowValMinus(n);
        vector<lli> rowValPlus(n);

        for (int col = 0; col < n; col++) {
            lli val = points[0][col];
            ans = max(ans, val);
            rowValMinus[col] = val - col;
            rowValPlus[col] = val + col;
        }
        


        for (int col = 1; col < n; col++) {
            rowValPlus[col] = max(rowValPlus[col], rowValPlus[col-1]);
        }

        for (int col = n-2; col >= 0; col--) {
            rowValMinus[col] = max(rowValMinus[col], rowValMinus[col+1]);
        }

        vector<lli> thisRowValMinus(n);
        vector<lli> thisRowValPlus(n);
        for (int row = 1; row < m; row++) {
            for (int col = 0; col < n; col++) {
                lli this_ans = -1e18;
                this_ans = max(this_ans, rowValPlus[col] - col + points[row][col]);
                this_ans = max(this_ans, rowValMinus[col] + col + points[row][col]);
                ans = max(ans, this_ans);
                thisRowValMinus[col] = this_ans - col;
                thisRowValPlus[col] = this_ans + col;
            }

            rowValMinus = thisRowValMinus;
            rowValPlus = thisRowValPlus;
            for (int col = 1; col < n; col++) {
                rowValPlus[col] = max(rowValPlus[col], rowValPlus[col-1]);
            }

            for (int col = n-2; col >= 0; col--) {
                rowValMinus[col] = max(rowValMinus[col], rowValMinus[col+1]);

            }
        }
        return ans;
    }
};

// dp[i, c] =  for c': (dp[i-1, c'] + points[i][c] - abs(c-c'))

// dp[i-1, c'] + points[i][c] - c'



// dp[i-1, c'] + points[i][c] + c'

