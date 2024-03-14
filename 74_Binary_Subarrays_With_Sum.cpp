class Solution {
public:
    int sum(vector<int> &nums, int goal){
        if(goal < 0)
            return 0;
        int left = 0, res = 0;
        for(int right = 0; right < nums.size(); right++){
            goal -= nums[right];
            while(goal < 0){
                goal += nums[left];
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sum(nums, goal) - sum(nums, goal - 1);
    }
};