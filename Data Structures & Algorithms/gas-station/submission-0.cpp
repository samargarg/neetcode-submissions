class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int this_total = 0;
        int n = gas.size();
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (this_total < 0) {
                this_total = 0;
                start = i;
            }
            this_total += (gas[i]-cost[i]);
            total += gas[i]-cost[i];
        }
        return (total >= 0 ? start : -1);
    }
}; 