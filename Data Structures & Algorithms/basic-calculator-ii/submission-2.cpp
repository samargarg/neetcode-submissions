class Solution {
public:
    int calculate(string s) {
        string current;
        unordered_set<char> sym = {'+', '-', '/', '*'};

        vector<string> v;
        for (int i = 0; i < s.size(); i++) {
            if (sym.count(s[i])) {
                v.push_back(current);
                string temp;
                temp.push_back(s[i]);
                v.push_back(temp);
                current = "";
            } else if (s[i] != ' ') {
                current += s[i];
            }
        }
        v.push_back(current);

        for (string k: v) {
            cout << k << " ";
        }
        cout << "\n";

        vector<string> u;
        for (int i = 0; i < v.size(); i++) {
            if (i && (v[i-1] == "*" || v[i-1] == "/")) {
                int ans = v[i-1] == "*" ? stoi(u[u.size()-2])*stoi(v[i]) : stoi(u[u.size()-2])/stoi(v[i]);
                u.pop_back();
                u.pop_back();
                u.push_back(to_string(ans));
            } else {
                u.push_back(v[i]);
            }
        }
        for (string k: u) {
            cout << k << " ";
        }
        cout << "\n";

        v = u;
        u.clear();
        for (int i = 0; i < v.size(); i++) {
            if (i && (v[i-1] == "+" || v[i-1] == "-")) {
                int ans = v[i-1] == "+" ? stoi(u[u.size()-2])+stoi(v[i]) : stoi(u[u.size()-2])-stoi(v[i]);
                u.pop_back();
                u.pop_back();
                u.push_back(to_string(ans));
            } else {
                u.push_back(v[i]);
            }
        }
        return stoi(u[0]);
        // return 0;
    }
};