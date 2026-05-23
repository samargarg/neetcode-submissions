class Solution {
public:
    bool isValid(string s) {
        vector<char> word;
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                word.push_back(c);
            } else {
                if (c == ')' && word.size() && word[word.size()-1] == '(') {
                    word.pop_back();
                } else if (c == '}' && word.size() && word[word.size()-1] == '{') {
                    word.pop_back();
                } else if (c == ']' && word.size() && word[word.size()-1] == '[') {
                    word.pop_back();
                } else {
                    return false;
                }
            }
        }
        return !word.size();
    }
};
