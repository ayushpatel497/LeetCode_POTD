class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int ct=0;
        for(auto i:s){
            if(i=='(')
                ct++;
            else if(i==')')
                ct--;
            if(ct>ans)
                ans=ct;
        }
        return ans;
    }
};