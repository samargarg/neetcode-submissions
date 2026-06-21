using ic = pair<int, char>;

class Solution {
public:
    
    string reorganizeString(string start) {
        set<ic> s;
        unordered_map<char, int> m;
        for (char c: start) {
            m[c]++;
        }
        for (auto [c, f]: m) {
            s.insert({f, c});
        }
        auto itr = s.end();
        itr--;
        if (itr->first > (start.size()+1)/2) {
            return "";
        }
        string ans = "";
        while (!s.empty()) {
            auto itr = s.end();
            itr--;
            if (ans.size() == 0 || (*itr).second != ans[ans.size()-1]) {
                ans += (*itr).second;
            } else {
                itr--;
                ans += (*itr).second;
            }
            ic mynew = {(*itr).first - 1, (*itr).second};
            
            if ((*itr).first > 1) {
                s.insert(mynew);
            }
            s.erase(itr);
            
        }
        return ans;
    }
};