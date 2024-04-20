class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int M = land.size(), N = land[0].size();
        vector<vector<int>> ans;
        
        for (int row = 0; row < M; row++) {
            for (int col = 0; col < N; col++) {
                if (land[row][col]) {
                    int x = row, y = col;
                    
                    for (x = row; x < M && land[x][col]; x++) {
                        for (y = col; y < N && land[x][y]; y++) {
                            land[x][y] = 0;
                        }
                    }

                    ans.push_back({row, col, x - 1, y - 1});
                }
            }
        }
        return ans;
    }
};