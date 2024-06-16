class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp = heights;
        sort(tmp.begin(), tmp.end());
        int ans = 0;
        for (int i = 0; i < tmp.size();i++)
            if (tmp[i] != heights[i])
                ans++;
        return ans;
    }
};