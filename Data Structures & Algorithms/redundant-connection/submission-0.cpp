class Solution {
    int n;
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        parent[x] = y;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size(); 
        parent.resize(n+1, -1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            if (find(a) != find(b)) {
                merge(a, b);
            } else {
                return edges[i];
            }
        }
    }
};
