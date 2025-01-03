class Solution {
public:
    int countSubsets(vector<int>& nums, int n, int m)
    {
        vector<vector<int>> t(n+1, vector<int>(m+1,0));
        for(int i=0; i<=n; i++)
        {
            t[i][0]=1;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][m];  
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
         target=abs(target);
         int n=nums.size();
         int sum=0;

         for(int i=0; i<n; i++)
             sum+=nums[i];

        int m=(sum+target)/2;
        if(sum<target||(sum+target)%2!=0)
            return 0;
        
        return countSubsets(nums, n, m);
    }  
};