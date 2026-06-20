class Solution {

    string current;
    string digits_;
    int n;
    vector<string> answer;

    map<char, vector<int>> comb;


    void createWords(int i) {
        if (i == n) {
            if (current != "") {
                answer.push_back(current);
            }
        }
        char c = digits_[i];
        for (int j: comb[c]) {
            current += ('a' + j);
            createWords(i+1);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        current = "";
        digits_ = digits;
        n = digits.size();
        answer.clear();
        int j = 0;
        for (int i = 2; i < 10; i++) {
            comb['0' + i] = {j, j+1, j+2};
            if (i == 7 || i == 9) {
                comb['0' + i].push_back(j+3);
                j++;
            }
            j += 3;
        }
        createWords(0);
        return answer;
    }
};
