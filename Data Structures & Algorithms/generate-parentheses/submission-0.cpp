class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return vector<string>{""};
        }
        vector<string> ans;
        vector<string> a = generateParenthesis(n-1);
        for (string s: a) {
            ans.push_back("(" + s + ")");
        }
        for (int i = 1; i <= n-1; i++) {
            vector<string> b = generateParenthesis(i-1);
            vector<string> c = generateParenthesis(n-i);
            for (string start: b) {
                for (string end: c) {
                    ans.push_back("(" + start + ")" + end);
                }
            }
            
        }
        return ans;
    }
};