class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int rep,miss;
        vector<int>v(n+1,0);
        for(int i:nums)
            v[i]++;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==0)
                miss = i;
            else if(v[i]==2)
                rep = i;
        }
        return {rep,miss};
    }
};
