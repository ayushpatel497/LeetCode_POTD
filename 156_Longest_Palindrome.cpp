class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128);
        for(char c:s)
            freq[c]++;
        int odd=0;
        for(auto i:freq)
            if(i%2)
                odd++;
        return s.size()-odd+(odd>0);
    }
};