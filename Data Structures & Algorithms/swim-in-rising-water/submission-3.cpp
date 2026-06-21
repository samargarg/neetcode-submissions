class Solution {
    vector<vector<int>> grid_;
    vector<vector<int>> dist;
    int n;
    using ii = pair<int, int>;

    vector<int> di = {0, 0, 1, -1};
    vector<int> dj = {1, -1, 0, 0};

    bool check(int i, int j) {
        return i >= 0 && i < n && j>= 0 && j < n;
    }

    void dijakstra(int i, int j) {
        dist[i][j] = grid_[i][j];
        priority_queue<pair<int, ii>> pq;
        pq.push({-dist[i][j], {i, j}});
        while (!pq.empty()) {
            auto [len, p] = pq.top(); pq.pop();
            auto [i, j] = p;
            len = -len;
            if (dist[i][j] < len) {
                continue;
            }
            for (int t = 0; t < 4; t++) {
                int i_ = i+di[t];
                int j_ = j+dj[t];
                if (check(i_, j_) && dist[i_][j_] > max(dist[i][j], grid_[i_][j_])) {
                    dist[i_][j_] = max(dist[i][j], grid_[i_][j_]);
                    pq.push({-dist[i_][j_], {i_, j_}});
                }
            }
        }
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        grid_ = grid;
        dist.assign(n, vector<int>(n, 1e9));
        dijakstra(0, 0);
        return dist[n-1][n-1];
    }
};