class Solution {

    bool check(int i, int j, vector<vector<char>>& board) {
        vector<bool> num(10, false);
        for (int a = i; a < i+3; a++) {
            for (int b = j; b < j+3; b++) {
                if (board[a][b] == '.') {
                    continue;
                }
                if (!num[board[a][b]]) {
                    num[board[a][b]] = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            vector<bool> num(10, false);
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (!num[board[i][j]]) {
                    num[board[i][j]] = true;
                } else {
                    return false;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            vector<bool> num(10, false);
            for (int j = 0; j < n; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (!num[board[j][i]]) {
                    num[board[j][i]] = true;
                } else {
                    return false;
                }
            }
        }
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                if (!check(i, j, board)) {
                    return false;
                }
            }
        }
        return true;
    }
};