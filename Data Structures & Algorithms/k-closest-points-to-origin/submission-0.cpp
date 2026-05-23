class Solution {

    int distt(vector<int> point) {
        return point[0]*point[0] + point[1]*point[1];
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int, vector<int>> m;
        for (int i = 0; i < points.size(); i++) {
            m[distt(points[i])].push_back(i);
        }
        vector<vector<int>> ans;
        for (auto p: m) {
            for (auto point: p.second) {
                ans.push_back(points[point]);
                k--;
                if (k == 0) {
                    break;
                }
            }
            if (k == 0) {
                break;
            }
        }
        return ans;
    }
};