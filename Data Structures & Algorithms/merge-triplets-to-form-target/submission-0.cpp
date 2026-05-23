class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        for (int i = 0; i < 3; i++) {
            bool possible = false;
            for (int j = 0; j < n; j++) {
                if (triplets[j][i] == target[i] && triplets[j][(i+1)%3] <= target[(i+1)%3] && triplets[j][(i+2)%3] <= target[(i+2)%3]) {
                    possible = true;
                    break;
                }
            }
            if (!possible) {
                return false;
            }
        }
        return true;
    }
};