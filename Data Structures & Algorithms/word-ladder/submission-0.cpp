class Solution {

    unordered_map<string, vector<string>> m;

    unordered_map<string, int> dist;

    void insertInMap(string word) {
        for (int i = 0; i < word.size(); i++) {
            string dup = word;
            dup[i] = '*';
            m[dup].push_back(word);
        }
    }

    void bfs(string beginword) {
        dist[beginword] = 0;
        queue<string> q;
        q.push(beginword);
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            cout << "s: " << s << "\n";

            for (int i = 0; i < s.size(); i++) {
                string dup = s;
                dup[i] = '*';
                for (string n: m[dup]) {
                    cout << n << "\n";
                    if (dist.find(n) == dist.end()) {
                        
                        dist[n] = dist[s] + 1;
                        cout << "dist of " << n << " is " << dist[n] << "\n";
                        q.push(n);
                    }
                }
            }
        }
    }


public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        m.clear();
        dist.clear();
        for (string word: wordList) {
            insertInMap(word);
        }
        insertInMap(beginWord);


        bfs(beginWord);
        if (dist.find(endWord) == dist.end()) {
            return 0;
        }
        return dist[endWord]+1;
    }
};
