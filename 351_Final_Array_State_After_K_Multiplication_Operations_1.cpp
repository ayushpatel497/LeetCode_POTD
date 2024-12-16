class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i=0; i<n; i++) {
            q.push({nums[i], i});
        }
        while(k--) {
            pair<int,int>p = q.top();
            q.pop();
            int val = p.first;
            int idx = p.second;
            nums[idx] = val*multiplier;
            q.push({nums[idx], idx});
        }
        return nums;
    }
};