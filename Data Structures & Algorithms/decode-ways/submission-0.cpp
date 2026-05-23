class Solution {
    string s_;
    int calc(int i) {
        if (i < 0) {
            return 1;
        }
        int ans = 0;
        int a = s_[i] - '0';
        // cout << "a: " << a << "\n";
        if (a > 0) {
            ans += calc(i-1);
        }
        if (i > 0) {
            int b = s_[i-1] - '0';
            // cout << "b: " << a << "\n";
            int c = 10*b + a;
            if (c >= 1 && c <= 26 && b != 0) {
                ans += calc(i-2);
            }
        }
        return ans;
    }


public:
    int numDecodings(string s) {
        int n = s.size();
        s_ = s;
        return calc(n-1);
    }
};
