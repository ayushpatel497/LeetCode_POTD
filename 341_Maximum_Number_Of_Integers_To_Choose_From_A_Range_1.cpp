class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> v(10001,0);
        for(int i=0; i<banned.size(); i++){
            v[banned[i]]=1;
        }

        long sum=0;
        int ct=0;
        for(int i=1; i<=n; i++){
            if(v[i]==1)
                continue;

            sum+=i;
            if(sum>maxSum)
               break;

            ct++;
        }

        return ct;
    }
};