class TimeMap {

    unordered_map<string, pair<vector<int>, vector<string>>> m;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        if (m.find(key) != m.end()) {
            vector<string> t = m[key].second;
            if (t[t.size()-1] == value) {
                return;
            }
        }
        m[key].first.push_back(timestamp);
        m[key].second.push_back(value);
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) {
            return "";
        }
        vector<int> times = m[key].first;
        auto itr = upper_bound(times.begin(), times.end(), timestamp);
        if (itr != times.begin()) {
            return m[key].second[distance(times.begin(), itr-1)];
        } else {
            return "";
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */