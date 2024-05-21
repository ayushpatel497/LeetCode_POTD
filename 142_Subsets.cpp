class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void helper(vector<int> &op,vector<int> &nums,int startIndex){
        if(startIndex == n){
            ans.push_back(op);
            return;
        }
        op.push_back(nums[startIndex]);
        helper(op,nums,startIndex + 1);
        op.pop_back();
        helper(op,nums,startIndex + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums){
        vector<int> op;
        n = nums.size();
        helper(op,nums,0);
        return ans;
    }
};