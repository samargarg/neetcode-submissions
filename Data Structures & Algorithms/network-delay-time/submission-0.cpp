class Solution {
    using ii = pair<int, int>;
    vector<vector<ii>> g;
    vector<int> dist;

    void bfs(int s) {
        dist[s] = 0;
        set<ii> myset;
        myset.insert({0, s});
        while (!myset.empty()) {
            auto [dist_of_v, v] = *myset.begin();
            myset.erase(myset.begin());
            if (dist_of_v != dist[v]) {
                continue;
            }
            for (auto [n, edge_l]: g[v]) {
                if (dist[n] > dist[v] + edge_l) {
                    dist[n] = dist[v] + edge_l;
                    myset.insert({dist[n], n});
                }
            }
        }
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        g.clear();
        g.resize(n+1);
        dist.clear();
        dist.assign(n+1, 1e9);
        for (vector<int> edge: times) {
            int u = edge[0];
            int v = edge[1];
            int l = edge[2];
            g[u].push_back({v, l});
        }

        bfs(k);
        int answer = 0;
        for (int i = 1; i <= n; i++) {
            answer = max(answer, dist[i]);
        }
        if (answer == 1e9) {
            return -1;
        }
        return answer;
    }
};
