class Leaderboard {
    unordered_map<int, int> hash;
    map<int, int> scoreVsCount;
public:
    Leaderboard() {
        scoreVsCount.clear();
        hash.clear();
    }
    
    void addScore(int playerId, int score) {
        int currentScore = hash[playerId];
        if (!currentScore) {
            hash[playerId] = -score;
            scoreVsCount[-score]++;
        } else {
            scoreVsCount[hash[playerId]]--;
            hash[playerId] -= score;
            scoreVsCount[hash[playerId]]++;
        }
    }
    
    int top(int K) {
        int counted = 0;
        int total = 0;
        for (auto [score, count]: scoreVsCount) {
            if (counted >= K) {
                break;
            }
            total += score*min(count, K-counted);
            counted += min(count, K-counted);
        }
        
        return -total;
    }
    
    void reset(int playerId) {
        scoreVsCount[hash[playerId]]--;
        hash.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
