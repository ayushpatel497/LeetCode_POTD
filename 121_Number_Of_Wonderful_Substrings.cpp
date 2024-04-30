class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> count(1024, 0);
        count[0] = 1;
        long long ans = 0;
        int bitmask = 0;

        for (char ch : word) {
            int charIndex = ch - 'a';
            bitmask ^= 1 << charIndex;
            ans += count[bitmask];
            for (int i = 0; i < 10; i++) {
                ans += count[bitmask ^ (1 << i)];
            }
            count[bitmask]++;
        }

        return ans;
    }
};