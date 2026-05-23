class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> alt(n);
        alt[n-1] = -1;
        for (int i = n-2; i >= 0; i--) {
            alt[i] = max(alt[i+1], arr[i+1]);
        }
        return alt;
    }
};