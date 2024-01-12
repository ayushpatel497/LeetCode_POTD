class Solution {
    private:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }
public:
    bool halvesAreAlike(string s) {
        int act=0;
        int bct=0;
        int n=s.length()/2;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])) act++;
        }
        for(int i=n;i<s.length();i++){
            if(isVowel(s[i])) bct++;
        }
        return act==bct;
    }
};