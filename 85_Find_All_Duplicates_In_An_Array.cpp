class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i:nums){
            int ind=abs(i)-1;
            if(nums[ind]>0)
                nums[ind]*=-1;
            else
                ans.push_back(ind+1);
        }
        return ans;
    }
};