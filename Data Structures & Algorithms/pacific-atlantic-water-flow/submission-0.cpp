class Solution {
    using ii = pair<int, int>;
    vector<vector<int>> visited;
    int n, m;

    bool isValid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        visited.assign(n, vector<int>(m, 0));
        queue<ii> q;
        for (int i = 0; i < n; i++) {
            visited[i][0] = 1;
            q.push({i, 0});
        }
        for (int j = 0; j < m; j++) {
            visited[0][j] = 1;
            q.push({0, j});
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int t = 0; t < 4; t++) {
                int i_ = i+dx[t];
                int j_ = j+dy[t];
                if (isValid(i_, j_) && visited[i_][j_] == 0 && heights[i_][j_] >= heights[i][j]) {
                    visited[i_][j_] = 1;
                    q.push({i_, j_});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << i << " " << j << " " << visited[i][j] << "\n";
                
            }
        }




        for (int i = 0; i < n; i++) {
            
            if (visited[i][m-1] == 1) {
                cout << "tr: " << i << m-1 << "\n";
                visited[i][m-1] = 3;
            } else {
                visited[i][m-1] = 2;
            }
            q.push({i, m-1});
        }
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << i << " " << j << " " << visited[i][j] << "\n";
                
            }
        }


        for (int j = 0; j < m; j++) {
            if (visited[n-1][j] == 1) {
                visited[n-1][j] = 3;
            } else if (visited[n-1][j] == 0) {
                visited[n-1][j] = 2;
            }
            q.push({n-1, j});
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << i << " " << j << " " << visited[i][j] << "\n";
                
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int t = 0; t < 4; t++) {
                int i_ = i+dx[t];
                int j_ = j+dy[t];
                if (isValid(i_, j_) && (visited[i_][j_] == 0 || visited[i_][j_] == 1) && heights[i_][j_] >= heights[i][j]) {
                    if (visited[i_][j_] == 1) {
                        visited[i_][j_] = 3;
                    } else {
                        visited[i_][j_] = 2;
                    }
                    q.push({i_, j_});
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << i << " " << j << " " << visited[i][j] << "\n";
                if (visited[i][j] == 3) {
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }
};
