class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int oneStudents = 0;
        for (int i: students) {
            oneStudents += i;
        }
        int zeroStudents = students.size()-oneStudents;

        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i]) {
                if (oneStudents) {
                    oneStudents--;
                } else {
                    return zeroStudents;
                }
            } else {
                if (zeroStudents) {
                    zeroStudents--;
                } else {
                    return oneStudents;
                }
            }
        }
        return 0;
    }
};