class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int sandInd = 0, studInd = 0, initStudInd, ans = students.size(), n = students.size();
        while (ans) {
            if (students[studInd] == sandwiches[sandInd]) {
                ans--;
                students[studInd] = -1;
                studInd = (studInd + 1) % n;
                sandInd++;
            }
            else {
                initStudInd = studInd;
                studInd = (studInd + 1) % n;
                while (students[studInd] != sandwiches[sandInd] && studInd != initStudInd) 
                    studInd = (studInd + 1) % n;
                if (studInd == initStudInd) 
                    break;
            }
        }
        return ans;
    }
};