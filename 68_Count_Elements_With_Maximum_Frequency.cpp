class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>um;
        int maxx=0;
        int ct=0;
        for(int i:nums){
            um[i]++;
            if(um[i]>maxx){
                maxx=um[i];
                ct=0;
            }
            if(um[i]==maxx)
                ct++;
        }
        return ct*maxx;
    }   
};