class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        for(auto c:nums){
            if(count == 0){
                ans = c;
                count = 1;
            }
            else if(ans == c) count++;
            else count--;
        }
        return ans;
    }
};