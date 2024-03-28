class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l=0,ans=0;
        for(int i=0; i<nums.size(); i++){
            if(++mp[nums[i]]>k)
                while(mp[nums[i]]>k && l<=i)
                    mp[nums[l++]]--;
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};