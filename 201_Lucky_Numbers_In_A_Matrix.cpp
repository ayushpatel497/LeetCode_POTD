class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0;i < matrix.size();i++){
            int mn = INT_MAX;
            for(int j = 0;j < matrix[0].size();j++){
                mn = min(mn, matrix[i][j]);
            }
            mp[mn]++;
        }
        for(int i = 0;i < matrix[0].size();i++){
            int mx = 0;
            for(int j = 0;j < matrix.size();j++){
                mx = max(mx, matrix[j][i]);
            }
            if(mp.count(mx))ans.push_back(mx);
        }
        return ans;
    }
};