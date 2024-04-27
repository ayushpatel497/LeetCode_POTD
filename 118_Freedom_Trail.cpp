class Solution {
public:
    int dfs(string& ring, string& key, int rIdx, int kIdx, vector<vector<int>>& memo) {
        if (kIdx == key.length()) 
            return 0;
        if (memo[rIdx][kIdx] != -1) 
            return memo[rIdx][kIdx];
        int minSteps = INT_MAX;
        int ringSize = ring.length();
        int kChar = key[kIdx];
        for (int i = 0; i < ringSize; ++i) {
            if (ring[i] == kChar) {
                int clockwiseSteps = (i - rIdx + ringSize) % ringSize;
                int anticlockwiseSteps = (rIdx - i + ringSize) % ringSize;
                int steps = min(clockwiseSteps, anticlockwiseSteps) + 1;
                steps += dfs(ring, key, i, kIdx + 1, memo);
                minSteps = min(minSteps, steps);
            }
        }
        memo[rIdx][kIdx] = minSteps;
        return minSteps;
    }

    int findRotateSteps(string ring, string key) {
        int ringSize = ring.length();
        int keySize = key.length();
        vector<vector<int>> memo(ringSize, vector<int>(keySize, -1));
        return dfs(ring, key, 0, 0, memo);
    }
};