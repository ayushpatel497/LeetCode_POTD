class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        if(grid.size()==1)
            return grid[0][0];
        int mn1=INT_MAX,mn2=INT_MAX,ind1=-1,ind2=-1,i,j,n=grid.size(),ans1=0,ans2=0,i1=-1,i2=-1;
        for(i = 0; i < n; i++){
            if(i==0){
                for(j = 0; j < n; j++){
                    if(grid[i][j] < mn1){
                        mn2 = mn1;
                        mn1 = grid[i][j];
                        ind1 = j;
                    }else if(grid[i][j]<mn2){
                        mn2 = grid[i][j];
                        ind2 = j;
                    }
                }
            }else{
                for(j = 0; j < n; j++){
                    if(j != ind1){
                        grid[i][j] += mn1;
                    }else{
                        grid[i][j] += mn2;
                    }
                }
                mn1 = mn2 = INT_MAX;
                for(j = 0; j < n; j++){
                    if(grid[i][j] < mn1){
                        mn2 = mn1;
                        mn1 = grid[i][j];
                        ind1 = j;
                    }else if(grid[i][j]<mn2){
                        mn2 = grid[i][j];
                        ind2 = j;
                    }
                }
            }
        }
        return min(mn1,mn2);
    }
};