class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for (string s: operations) {
            if (s == "+") {
                int t = ans[ans.size()-1] + ans[ans.size()-2];
                ans.push_back(t);
            } else if (s == "D") {
                int t = 2*ans[ans.size()-1];
                ans.push_back(t);
            } else if (s == "C") {
                ans.pop_back();
            } else {
                int t = stoi(s);
                ans.push_back(t);
            }
        }
        int fina = 0;
        for (int i: ans) {
            fina += i;
        }
        return fina;
    }
};