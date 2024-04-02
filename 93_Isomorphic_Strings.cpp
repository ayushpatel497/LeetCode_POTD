class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        int smp[256] = {0},tmp[256] = {0};
        for(int i=0; i<s.length(); i++){
            if(smp[s[i]]!=tmp[t[i]]) return false;
            smp[s[i]]=i+1;
            tmp[t[i]]=i+1;
        }
        return true;
    }
};