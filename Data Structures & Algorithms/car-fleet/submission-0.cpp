class Solution {
    using ii = pair<long, long>;
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<ii> car(n);
        for (int i = 0; i < n; i++) {
            car[i] = {-position[i], speed[i]};
        }
        sort(car.begin(), car.end());
        ii slowest = car[0];
        ii dis_speed = {target+slowest.first, slowest.second};
        int fleets = n;
        for (int i = 1; i < n; i++) {
            int pos = -car[i].first;
            int speed = car[i].second;
            ii this_dis_speed = {target-pos, speed};
            // cout << i << " " << this_time << " " << time << "\n";
            if (this_dis_speed.first*dis_speed.second <= dis_speed.first*this_dis_speed.second) {
                fleets--;
            } else {
                dis_speed = this_dis_speed;
            }
        }
        return fleets;
    }
};