class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
		vector<int> ans;
        ans.emplace_back(nums[0]);
        for(int i =1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.emplace_back(nums[i]);
            }else{
                int ind = lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[ind]=nums[i];
            }
        }
        return ans.size();
    }
};