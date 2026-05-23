


class Solution {
    vector<string> tokens_;
    bool isChar(string s) {
        if (s.size() != 1) {
            return false;
        }
        char sign = s[0];
        switch (sign) {
            case '+':
                return true;
            case '-':
                return true;
            case '*':
                return true;
            case '/':
                return true;
            default:
                return false;
        }
    }

    int calc(int a, int b, char sign) {
        switch (sign) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                throw std::runtime_error("Invalid operator");
        }
    }


public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        tokens_ = tokens;
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (isChar(tokens[i])) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int ans = calc(a, b, tokens[i][0]);
                cout << "calc: " << a << " " << b << " " << tokens[i][0] << "\n";
                cout << ans << "\n";
                s.push(ans);
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};