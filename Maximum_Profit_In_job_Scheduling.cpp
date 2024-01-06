class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size(); 
        vector<pair<int, int>> vpst(n);
        for(int i = 0; i < n; i++) 
            vpst[i] = {startTime[i], i};
        sort(vpst.begin(), vpst.end());
        vector<int> dp(n+1, 0); 
        for(int i = n-1; i >=0; i--)
            dp[i] += max(dp[i+1], profit[vpst[i].second] + dp[lower_bound(vpst.begin() + i, vpst.end(), make_pair(endTime[vpst[i].second], 0)) - vpst.begin()]);
        return dp[0];
    }
};