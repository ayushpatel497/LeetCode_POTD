class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int i, co=0, sum=0, ans=0;
        for(i=0;i<arr.size();i++)
        {
            sum+=i;
            co+=arr[i];
            if(sum==co)
                ans++;
        }
        return ans;
    }
};