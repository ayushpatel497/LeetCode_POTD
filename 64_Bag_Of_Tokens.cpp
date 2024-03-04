class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int maxScore = 0;
        int i = 0;
        int j = tokens.size() - 1;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                score += 1;
                i += 1;
                maxScore = max(maxScore, score);
            } else if (score > 0) {
                power += tokens[j];
                score -= 1;
                j -= 1;
            } else {
                break;
            }
        }
        return maxScore;
    }
};