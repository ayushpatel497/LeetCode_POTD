class Solution {
public:
    int minDifference(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int k = 3;
        if (nums.size() <= k + 1) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int diff = nums.back() - nums[k];
        int res = diff;
        for (int i = 1; i <= k; i++) { 
            diff = nums[nums.size() - 1 - i] - nums[k - i];
            res = min(diff, res);
        }
        return res;
    }
};