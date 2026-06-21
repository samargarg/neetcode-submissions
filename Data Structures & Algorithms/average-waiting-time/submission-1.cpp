class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int last_waiting = 0;
        int n = customers.size();
        long long total = 0;
        for (int i = 0; i < n; i++) {
            vector<int> cust = customers[i];
            int arr = cust[0];
            int tim = cust[1];
            int pending_ = i ? max(customers[i-1][0] + last_waiting - arr, 0): 0;
            last_waiting = pending_ + tim;
            total += last_waiting;
        }
        return ((double) total)/n;
    }
};