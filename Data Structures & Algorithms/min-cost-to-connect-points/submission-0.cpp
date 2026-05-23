class Solution {
    using ii = pair<int, int>;

    int n;
    vector<vector<int>> points_;
    vector<vector<int>> edges;
    vector<int> parent;

    int dis(int i, int j) {
        int x1 = points_[i][0];
        int y1 = points_[i][1];
        int x2 = points_[j][0];
        int y2 = points_[j][1];
        return abs(x1-x2) + abs(y1-y2);
    }

    int find(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }
        parent[a] = b;
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        points_ = points;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                edges.push_back(vector<int>{dis(i, j), i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int min_cost = 0;
        int used_edges = 0;
        for (auto edge: edges) {
            int length = edge[0];
            int a = edge[1];
            int b = edge[2];
            if (find(a) != find(b)) {
                merge(a, b);
                min_cost += length;
                used_edges++;
            }
            if (used_edges == n-1) {
                break;
            }
        }
        return min_cost;
    }
};
