class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxx = *max_element(nums.begin(), nums.end()), n = nums.size(), cur = 0, j = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i] == maxx;
            while (cur >= k)
                cur -= nums[j++] == maxx;
            ans += j;
        }
        return ans;
    }
};