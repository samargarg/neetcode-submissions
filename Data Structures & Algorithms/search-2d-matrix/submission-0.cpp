class Solution {

    vector<vector<int>> matrix_;

    bool check(int x, int target) {
        int row = x/m;
        int col = x % m;
        return matrix_[row][col] <= target;
    }

    int n, m;
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        n = matrix.size();
        m = matrix[0].size();
        matrix_ = matrix;
        int low = 0;
        int high = m*n-1;
        int ans = 1e9;
        while (low <= high) {
            int mid = (low+high)/2;
            if (check(mid, target)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        if (ans == 1e9) {
            return false;
        }
        int row = ans/m;
        int col = ans % m;
        return matrix[row][col] == target;
    }
};