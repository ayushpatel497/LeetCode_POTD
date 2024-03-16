class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0, maxx=0;
        unordered_map<int, int> um{{0, -1}};
        for(int i=0; i<nums.size(); i++){
            sum += nums[i]==1 ? 1 : -1;
            if(um.count(sum)) maxx = max(maxx, i-um[sum]);
            else um[sum] = i;
        }
        return maxx;
    }
};