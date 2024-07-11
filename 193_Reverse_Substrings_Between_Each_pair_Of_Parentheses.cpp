class Solution {
public:
    string reverseParentheses(string s) {
        deque<int> ind_stack;
        vector<char> ans;
        for (char char_s : s) {
            if (char_s == '(') {
                ind_stack.push_back(ans.size());
            } else if (char_s == ')') {
                int start_ind = ind_stack.back();
                ind_stack.pop_back();
                reverse(ans.begin() + start_ind, ans.end());
            } else {
                ans.push_back(char_s);
            }
        }
        return string(ans.begin(), ans.end());
    }
};