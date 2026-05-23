class Solution {

    map<string, vector<pair<string, bool>>> g;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, int> m;

        for (vector<string> ticket: tickets) {
            string a = ticket[0];
            string b = ticket[1];
            g[a].push_back({b, false});
            m[a] -= 1;
            m[b] += 1;
        }
        string start, end;
        for (pair<string, int> p: m) {
            if (p.second == -1) {
                start = p.first;
            } else if (p.second == 1) {
                end = p.first;
            }
        }

        for (auto &p: g) {
            sort(p.second.begin(), p.second.end());
        }
        stack<string> s;
        s.push("JFK");
        
        vector<string> seq;
        while (!s.empty()) {
            string v = s.top();
            for (auto &p: g[v]) {
                if (!p.second) {
                    p.second = true;
                    s.push(p.first);
                    break;
                }
            }
            if (s.top() == v) {
                seq.push_back(v);
                s.pop();
            }
        }
        reverse(seq.begin(), seq.end());
        return seq;
    }
};
