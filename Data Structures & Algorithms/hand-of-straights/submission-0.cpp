class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n%groupSize) {
            return false;
        }
        unordered_map<int, int> card_count;
        for (int card: hand) {
            card_count[card]++;
        }
        int card = hand[0];
        while (card_count[card-1] != 0) {
            card--;
        }
        for (int card: hand) {
            int first_card = card;
            while (card_count[first_card-1] != 0) {
                first_card--;
            }
            while (first_card <= card) {
                while (card_count[first_card]) {
                    for (int i = first_card; i < first_card+groupSize; i++) {
                        if (card_count[i] == 0) {
                            return false;
                        } else {
                            card_count[i]--;
                            if (card_count[i] == 0) {
                                card_count.erase(i);
                            }
                        }
                    }
                }
                first_card++;
            }
        }
        return true;

    }
};
