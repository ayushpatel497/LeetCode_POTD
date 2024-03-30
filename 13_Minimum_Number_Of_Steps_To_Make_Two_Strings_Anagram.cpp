class Solution {
public:
    int minSteps(string s, string t) {
        int alpha[26]={0};
        int ans=0;
        for(int i=0;i<t.length();i++){
            alpha[t[i]-'a']++;
            alpha[s[i]-'a']--;
        }
        for(auto i:alpha){
            if(i>=0) ans+=i;
        }
        return ans>0?ans:0;
    }
};
