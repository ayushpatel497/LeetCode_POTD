class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us(nums1.begin(), nums1.end());
        vector<int> ans;
        for (auto i : nums2)
            if (us.count(i)) {
                ans.push_back(i);
                us.erase(i);
            }
        return ans;
    }
};