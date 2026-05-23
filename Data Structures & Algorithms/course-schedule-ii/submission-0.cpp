class Solution {
    vector<int> indegree;
    int n;
    vector<vector<int>> g;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        g.resize(n);
        indegree.assign(n, 0);
        queue<int> q;
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            g[b].push_back(a);
            indegree[a]++;
        }
        vector<int> answer;
        for (int i = 0; i < n; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int v = q.front();
            answer.push_back(v);
            q.pop();
            for (int n: g[v]) {
                indegree[n]--;
                if (!indegree[n]) {
                    q.push(n);
                }
            }
        }
        if (answer.size() != n) {
            return vector<int>{};
        }
        return answer;
    }
};
