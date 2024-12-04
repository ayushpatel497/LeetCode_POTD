class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int n = str2.length();
        for (char currChar : str1) {
            if (i < n && (str2[i] - currChar + 26) % 26 <= 1) {
                i++;
            }
        }
        return i == n;
    }
};