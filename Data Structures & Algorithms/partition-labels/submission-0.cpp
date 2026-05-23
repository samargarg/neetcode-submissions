class Solution {

    unordered_map<char, int> gen;
    unordered_map<char, int> spec;

    bool check() {
        for (pair<char, int> p: spec) {
            if (p.second < gen[p.first]) {
                return false;
            }
        }
        return true;
    }

public:
    vector<int> partitionLabels(string s) {

        for (char c: s) {
            gen[c]++;
        }

        vector<int> sizes;
        int last = -1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            spec[c]++;
            if (check()) {
                sizes.push_back(i-last);
                last = i;
                spec.clear();
            }
        }
        return sizes;
    }
};