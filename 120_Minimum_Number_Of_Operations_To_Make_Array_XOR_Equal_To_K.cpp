class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(auto &i: nums){
            k ^= i;
        }
        while(k){
            ans += (k&1);
            k>>=1;
        }
        return ans;
    }
};