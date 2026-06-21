class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        vector<int> dist_(n, 1e9);
        dist[src] = 0;
        dist_[src] = 0;
        for (int i = 0; i < k+1; i++) {
            for (vector<int> flight: flights) {
                if (dist[flight[0]] != 1e9) {
                    dist_[flight[1]] = min(dist_[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            dist = dist_;
        }
        if (dist_[dst] == 1e9) {
            return -1;
        }
        return dist_[dst];
    }
};
