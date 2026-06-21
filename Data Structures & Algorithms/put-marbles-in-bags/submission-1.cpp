using lli = long long;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> A;
        int n = weights.size();
        for (int i = 0; i < n-1; i++) {
            A.push_back(weights[i] + weights[i+1]);
        }

        sort(A.begin(), A.end());
        lli maxi = 0;
        lli mini = 0;
        for (int i = 0; i < n-k; i++) {
            maxi += A[i];
            mini += A[n-1-i-1];
        }
        return mini-maxi;
    }
};