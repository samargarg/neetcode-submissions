class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int times = k+1;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (times--) {
            vector<int> dist_copy = dist;
            for (int i = 0; i < n; i++) {
                cout << dist_copy[i] << "\n";
            }
            cout << "\n";
            for (vector<int> flight: flights) {
                int a = flight[0];
                int b = flight[1];
                int price = flight[2];
                cout << a << " " << b << "\n";
                cout << min(dist[b], dist[a] + price) << "\n";
                dist_copy[b] = min(dist_copy[b], dist[a] + price);
            }
            
            dist = dist_copy;
            for (int i = 0; i < n; i++) {
                cout << dist[i] << "\n";
            }
            cout << "\n";
        }
        if (dist[dst] == 1e9) {
            return -1;
        }
        return dist[dst];
        
    }
};
