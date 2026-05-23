class Solution {

    vector<vector<int>> g;
    vector<int> inorder;
    bool compare(string a, string b) {
        
        for (int i = 0; i < min(a.size(), b.size()); i++) {
            if (a[i] != b[i]) {
                g[a[i] - 'a'].push_back(b[i] - 'a');
                return true;
            }
        }
        if (a.size() > b.size()) {
            return false;
        }
        return true;
    }

    set<int> letters;

public:
    string foreignDictionary(vector<string>& words) {
        g.resize(26);
        for (int i = 1; i < words.size(); i++) {
            if (!compare(words[i-1], words[i])) {
                return "";
            }
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                letters.insert(words[i][j] - 'a');
            }
        }
        inorder.resize(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j: g[i]) {
                inorder[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (letters.count(i) && !inorder[i]) {
                q.push(i);
            }
        }
        string s;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            s += ('a' + v);
            for (int n: g[v]) {
                inorder[n]--;
                if (!inorder[n]) {
                    q.push(n);
                }
            }
        }
        if (s.size() != letters.size()) {
            return "";
        }
        return s;
    }
};
