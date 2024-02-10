class Solution {
private:
    int palindrome(int i, int j,string &s){
        int cnt = 0;
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i = 0; i < s.length() ;i++){
           int j = i;
           int oddLengthVal = palindrome(i, j, s);
           int evenLengthVal= palindrome(i, j+1, s);
           cnt += (oddLengthVal + evenLengthVal);
        }
        return cnt;
    }
};