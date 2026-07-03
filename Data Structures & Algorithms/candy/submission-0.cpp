using ii = pair<int, int>;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<ii> v;
        for (int i = 0; i < n; i++) {
            v.push_back({ratings[i], i});
        }
        sort(v.begin(), v.end());

        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++) {
            auto [rating, index] = v[i];
            if (index && ratings[index-1] < rating) {
                answer[index] = answer[index-1]+1;
            }
            if (index+1 < n && ratings[index+1] < rating) {
                answer[index] = max(answer[index], answer[index+1]+1);
            }
            answer[index] = max(answer[index], 1);
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += answer[i];
        }
        return total;
    }
};