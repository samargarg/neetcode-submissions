class Solution {

    string sortString(string s) {
        sort(s.begin(), s.end());
        return s;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> ans;
        for (string s: strs) {
            ans[sortString(s)].push_back(s);
        }
        vector<vector<string>> fans;
        for (auto [sorted, mylist]: ans) {
            fans.push_back(mylist);
        }
        return fans;
    }
};