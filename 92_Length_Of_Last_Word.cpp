class Solution {
public:
    int lengthOfLastWord(string s) {
        int ct=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' ')
                ct++;
            else if(ct>=1 )
                break;   
        }
        return ct;
    }
};