class Solution {
    vector<vector<int>> g;
    vector<bool> visited;
    void dfs(int i) {
        visited[i] = true;
        for (int n: g[i]) {
            if (!visited[n]) {
                dfs(n);
            }
        }
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) {
            return false;
        }
        g.resize(n);
        visited.resize(n, false);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};
