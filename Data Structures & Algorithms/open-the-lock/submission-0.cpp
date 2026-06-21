class Solution {


public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> dist;
        unordered_set<string> d;
        for (string s: deadends) {
            d.insert(s);
        }
        dist["0000"] = 0;
        queue<string> q;
        q.push("0000");
        while (!q.empty()) {
            string node = q.front();
            q.pop();
            if (d.count(node)) {
                continue;
            } 
            for (int i = 0; i < 4; i++) {
                for (int j: {1, 9}) {
                    string neigh = node;
                    neigh[i] = (((neigh[i] - '0') + j)%10) + '0';
                    if (!dist.count(neigh) || dist[neigh] > dist[node] + 1) {
                        dist[neigh] = dist[node] + 1;
                        q.push(neigh);
                    }
                }
            }

        }
        if (dist.count(target)) {
            return dist[target];
        } else {
            return -1;
        }
    }
};