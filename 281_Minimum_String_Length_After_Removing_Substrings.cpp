class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        if (n<2) 
            return n;
        int sz=1;
        for(int i=1; i<n; i++){
            s[sz]=s[i];
            if (sz>0 &&((s[sz-1]=='A' && s[i]=='B') ||
                (s[sz-1]=='C' && s[i]=='D'))) sz--;
            else sz++;
        }  
        return sz;  
    }
};