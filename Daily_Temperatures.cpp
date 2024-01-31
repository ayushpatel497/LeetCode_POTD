class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        stack<int> st;
        st.push(len - 1);
        vector<int> ans(len);
        for (int i = len - 2, n; i >=0; --i) {
            n = temperatures[i];
            while (!st.empty() && n >= temperatures[st.top()]) st.pop();
            if (!st.empty()) ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};