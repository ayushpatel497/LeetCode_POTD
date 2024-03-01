class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0;
        for (auto a : s) {
            if (a == '1') one++;
        }
        return string(one - 1, '1') + string((s.length()-one), '0') + '1';
    }
};