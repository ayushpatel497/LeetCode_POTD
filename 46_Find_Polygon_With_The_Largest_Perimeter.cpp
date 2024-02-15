class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=2;
        long long sum=0,cur=0;
        sum=1L*(nums[0]+nums[1]);
        for(int i=2;i<nums.size();i++){
            if(1L*nums[i]<sum){
                sum+=1L*nums[i];
                cur=sum;
                count++;
            }
            else{
                sum+=1L*nums[i];
            }
        }
        if(count==2){
            return -1;
        }
        return cur;
    }
};