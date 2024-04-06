class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        string ans = "";
        int ct = 0;
        for (auto &i:s)
        {
            if (i == '(')
                ct++;
            else if (i == ')')
            {
                if (ct == 0)
                    i = '*';
                else
                    ct--;
            }
        }

        ct = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                ct++;
            else if (s[i] == '(')
            {
                if (ct == 0)
                    s[i] = '*';
                else
                    ct--;
            }
        }

        for (auto i:s)
            if (i != '*')
                ans.push_back(i);
        return ans;
    }
};